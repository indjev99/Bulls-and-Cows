#ifndef MCTS_H_INCLUDED
#define MCTS_H_INCLUDED

#include "response.h"
#include "valid_tracker.h"

struct Node
{
    Node();

    void mcts(int iters);

    Response getResponse();
    int getGuess();

    void giveResponse(Response response);
    void giveGuess(int guess);

    void mcts(const ValidTracker& tracker, int numIters);
    void mctsIteration(ValidTracker tracker);

private:

    int turns;
    bool terminal;
    bool guesserToPlay;

    int guess;
    Response response;

    double prior;
    int visitCount;
    double valueSum;
    double value();

    std::vector<Node> children;

    Node(int turns, int guess, double prior);
    Node(int turns, Response response, double prior);

    Node* selectChild();
    Node& selectMove();

    void expand(const ValidTracker& tracker);
    double evaluate(const ValidTracker& tracker);
};

void testMcts();

#endif // MCTS_H_INCLUDED
