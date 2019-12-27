#include "mcts.h"
#include "utils.h"
#include <algorithm>
#include <math.h>
#include <assert.h>

#include <iostream>
using namespace std;

static const double c_init = 1.25;
static const double base_turns = 7;
static const double log_scale = log(pow(validNumbers.size(), 1 / (base_turns - 1)));

Node::Node():
    turns(0),
    terminal(false),
    guesserToPlay(true),
    prior(1),
    visitCount(0),
    valueSum(0) {}

Node::Node(int turns, int guess, double prior):
    turns(turns),
    terminal(false),
    guesserToPlay(false),
    guess(guess),
    prior(prior),
    visitCount(0),
    valueSum(0) {}

Node::Node(int turns, Response response, double prior):
    turns(turns),
    terminal(isResponseFinal(response)),
    guesserToPlay(true),
    response(response),
    prior(prior),
    visitCount(0),
    valueSum(0) {}

double Node::value()
{
    if (visitCount == 0) return 0;
    return valueSum / visitCount;
}

Node* Node::selectChild()
{
    double maxScore = -1e9;
    Node* bestChild = nullptr;

    for (Node& child : children)
    {
        double score = child.value() + c_init * child.prior * sqrt(visitCount) / (1 + child.visitCount);
        if (score > maxScore)
        {
            maxScore = score;
            bestChild = &child;
        }
    }
    return bestChild;
}

Node& Node::selectMove()
{
    int maxVisits = -1;
    Node* bestChild = nullptr;

    for (Node& child : children)
    {
        if (child.visitCount > maxVisits)
        {
            maxVisits = child.visitCount;
            bestChild = &child;
        }
    }
    return *bestChild;
}

int Node::getGuess()
{
    assert(guesserToPlay);
    Node child = selectMove();
    //cerr << "evals: " << child.visitCount << " " << child.value() << endl;
    int guess = child.guess;
    *this = child;
    return guess;
}

Response Node::getResponse()
{
    assert(!guesserToPlay);
    Node child = selectMove();
    //cerr << "evals: " << child.visitCount << " " << child.value() << endl;
    Response response = child.response;
    *this = child;
    return response;
}

void Node::expand(const ValidTracker& tracker)
{
    if (guesserToPlay)
    {
        double norm = 1.0 / (validNumbers.size() + tracker.numValid());
        std::vector<int> permutation(validNumbers.begin(), validNumbers.end());
        std::random_shuffle(permutation.begin(), permutation.end());
        for (int guess : permutation)
        {
            children.push_back(Node(turns, guess, (1 + tracker.isValid(guess)) * norm));
        }
    }
    else
    {
        double norm = 1.0 / tracker.numValid();
        std::vector<ValidTracker> splits = tracker.split(guess);
        for (Response response : validResponses)
        {
            const ValidTracker& curr = splits[responseToIndex(response)];
            if (curr.numValid() == 0) continue;
            children.push_back(Node(turns + 1, response, curr.numValid() * norm));
        }
    }
}

double Node::evaluate(const ValidTracker& tracker)
{
    if (terminal)
    {
        return turns - base_turns;
    }
    else if (guesserToPlay)
    {
        expand(tracker);
        return turns + log(tracker.numValid()) / log_scale + 1 - base_turns;
    }
    else
    {
        expand(tracker);
        return turns + log(tracker.worstSplitSize(guess)) / log_scale + 2 - base_turns;
    }
}

void Node::mctsIteration(ValidTracker tracker)
{
    Node* nodePtr = this;

    std::vector<Node*> history = {nodePtr};
    int lastGuess = nodePtr->guess;

    //cerr << "state: " << nodePtr->turns << " " << nodePtr->terminal << " = " << tracker.numValid();
    //if (!nodePtr->guesserToPlay) cerr << "\nthinker " << nodePtr->guess;
    //else cerr << "\nguesser " << nodePtr->response.bulls << " " << nodePtr->response.cows;
    //cerr << "\nstats: " << nodePtr->prior << " " << nodePtr->value() << " " << nodePtr->visitCount << "\n";

    while (!nodePtr->children.empty())
    {
        nodePtr = nodePtr->selectChild();
        if (!nodePtr->guesserToPlay) lastGuess = nodePtr->guess;
        else tracker.update(lastGuess, nodePtr->response);
        history.push_back(nodePtr);

        //cerr << "state: " << nodePtr->turns << " " << nodePtr->terminal << " = " << tracker.numValid();
        //if (!nodePtr->guesserToPlay) cerr << "\nthinker " << nodePtr->guess;
        //else cerr << "\nguesser " << nodePtr->response.bulls << " " << nodePtr->response.cows;
        //cerr << "\nstats: " << nodePtr->prior << " " << nodePtr->value() << " " << nodePtr->visitCount << "\n";
    }
    double value = nodePtr->evaluate(tracker);
    for (Node* nodePtr : history)
    {
        ++(nodePtr->visitCount);
        if (nodePtr->guesserToPlay) nodePtr->valueSum += value;
        else nodePtr->valueSum -= value;
    }
}

void Node::mcts(const ValidTracker& tracker, int numIters)
{
    for (int i = 0; i < numIters; ++i)
    {
        //if (i % 100 == 0) cerr << i << endl;
        mctsIteration(tracker);
    }
    //cerr << endl;
}
