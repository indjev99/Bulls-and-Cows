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

static int selectDifficulty(int maxDifficulty, std::string adjective =  "\b")
{
    int difficulty = 0;
    while (difficulty < 1 || difficulty > maxDifficulty)
    {
        std::cout << "Select " << adjective << " difficulty (1 - " << maxDifficulty << "): ";
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

static void settings()
{
    int numDigits;
    std::cout << "Enter the number of digits: ";
    std::cin >> numDigits;
    setParams(numDigits);
}

static void test()
{
    int gDifficulty = selectDifficulty(guessers.size(), "guesser");
    int tDifficulty = selectDifficulty(thinkers.size(), "thinker");
    int numGames;
    std::cout << "Number of games: ";
    std::cin >> numGames;
    profile(guessers[gDifficulty - 1], thinkers[tDifficulty - 1], -1, numGames, true);
}

static const std::string help = "Possible commands: guess / g, think / t, settings, test, credits, help, exit.";
static const std::string credits = "Made by Emil Indzhev.";
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
        else if (command == "settings") settings();
        else if (command == "test") test();
        else if (command == "credits") std::cout << credits << std::endl;
        else if (command == "help") std::cout << help << std::endl;
        else if (command == "exit") break;
    }
}

int main()
{
    initRandomizer();
    setParams(4);

    shell();

    return 0;
}
