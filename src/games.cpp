#include "games.h"
#include "play.h"
#include "utils.h"
#include "fixed_thinker.h"
#include <iostream>

void battle(Guesser* guesser1, Thinker* thinker1, Guesser* guesser2, Thinker* thinker2, double timeLimit, int numGames, bool verbose)
{
    int p1Wins = 0;
    int p2Wins = 0;
    int draws = 0;
    for (int i = 0; i < numGames; ++i)
    {
        int result = playGame(guesser1, thinker1, guesser2, thinker2, timeLimit);
        switch (result)
        {
        case P1_WIN:
            ++p1Wins;
            if (verbose) std::cout << "+";
            break;
        case P2_WIN:
            ++p2Wins;
            if (verbose) std::cout << "-";
            break;
        case DRAW:
            ++draws;
            if (verbose) std::cout << "0";
            break;
        default:
            if (verbose) std::cout << " Error! ";
        }
    }
    if (verbose) std::cout << std::endl;

    std::cout << "Player 1 wins: " << p1Wins << std::endl;
    std::cout << "Player 2 wins: " << p2Wins << std::endl;
    std::cout << "Draws: " << draws << std::endl;
}

void profile(Guesser* guesser, double timeLimit, int numIterations)
{
    FixedThinker thinker;
    double avgRes = 0;
    int maxRes = 0;
    int cnt = 0;
    for (int number : validNumbers)
    {
        for (int i = 0; i < numIterations; ++i)
        {
            thinker.setNumber(number);
            int result = playRound(guesser, &thinker, timeLimit);
            avgRes += result;
            maxRes = std::max(maxRes, result);
            //std::cerr << number << " : " << result << std::endl;
        }
        if (cnt % 100 == 0) std::cout << ".";
        ++cnt;
    }
    avgRes /= validNumbers.size() * numIterations;
    std::cout << std::endl;

    if (maxRes == G_FAIL)
    {
        std::cout << "Doesn't always guess correctly." << std::endl;
    }
    else
    {
        std::cout << "Average number of guesses needed: " << avgRes << std::endl;
        std::cout << "Maximum number of guesses needed: " << maxRes << std::endl;
    }
}

void profile(Guesser* guesser, Thinker* thinker, double timeLimit, int numGames)
{
    double avgRes = 0;
    int maxRes = 0;
    for (int i = 0; i < numGames; ++i)
    {
        int result = playRound(guesser, thinker, timeLimit);
        avgRes += result;
        maxRes = std::max(maxRes, result);
        std::cerr << result << " ";
    }
    avgRes /= numGames;
    std::cerr << std::endl;

    if (maxRes == G_FAIL)
    {
        std::cout << "Doesn't always guess correctly." << std::endl;
    }
    else
    {
        std::cout << "Average number of guesses needed: " << avgRes << std::endl;
        std::cout << "Maximum number of guesses needed: " << maxRes << std::endl;
    }
}
