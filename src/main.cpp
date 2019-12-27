#include "utils.h"
#include "games.h"
#include "all_players.h"
#include <iostream>

RandomGuesser randomGuesser;
DummyGuesser dummyGuesser;
ValidGuesser validGuesser;
GreedyGuesser greedyGuesser;
LookaheadGuesser lookaheadGuesser;
UserGuesser userGuesser;

RandomThinker randomThinker;
ValidThinker validThinker;
GreedyThinker greedyThinker;
LookaheadThinker lookaheadThinker;
UserThinker userThinker;

static std::vector<Guesser*> guessers = {&dummyGuesser, &validGuesser, &greedyGuesser, &lookaheadGuesser};
static std::vector<Thinker*> thinkers = {&randomThinker, &validThinker, &greedyThinker, &lookaheadThinker};

static int selectDifficulty(int maxDifficulty)
{
    int difficulty = 0;
    while (difficulty < 1 || difficulty > maxDifficulty)
    {
        std::cout << "Select difficulty (1 - " << maxDifficulty << "): ";
        std::cin >> difficulty;
    }
    return difficulty;
}

static void userGuess()
{
    int difficulty = selectDifficulty(thinkers.size());
    single(&userGuesser, thinkers[difficulty - 1], -1);
}

static void userThink()
{
    int difficulty = selectDifficulty(guessers.size());
    single(guessers[difficulty - 1], &userThinker, -1);
}

const std::string help = "Possible commands: guess / g, think / t, credits, help, exit.";
const std::string credits = "Made by Emil Indzhev.";
void shell()
{
    std::string command;
    std::cout << help << std::endl;
    while (true)
    {
        std::cout << "\nEnter command: ";
        std::cin >> command;
        if (command == "guess" || command == "g") userGuess();
        else if (command == "think" || command == "t") userThink();
        else if (command == "credits") std::cout << credits << std::endl;
        else if (command == "help") std::cout << help << std::endl;
        else if (command == "exit") break;
    }
}

//#include "mcts.h"

int main()
{
    initRandomizer();

    shell();

    /*ValidTracker tracker;

    while (true)
    {
        Node node;
        tracker.reset();

        while (true)
        {
            node.mcts(tracker, 2500);
            int guess = node.getGuess();
            std::cerr << guess << std::endl;

            node.mcts(tracker, 2500);
            Response response = node.getResponse();
            std::cerr << response.bulls << " " << response.cows << std::endl;

            tracker.update(guess, response);

            if (isResponseFinal(response)) break;
        }
    }*/

    return 0;
}
