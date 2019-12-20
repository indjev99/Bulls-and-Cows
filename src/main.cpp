#include "utils.h"
#include "play.h"
#include "random_guesser.h"
#include "random_thinker.h"
#include <iostream>

static const int GAMES = 1000;

int main()
{
    initRandomizer();

    RandomGuesser guesser1;
    RandomThinker thinker1;

    RandomGuesser guesser2;
    RandomThinker thinker2;

    int score = 0;
    int p1Wins = 0;
    int p2Wins = 0;
    int draws = 0;
    for (int i = 0; i < GAMES; ++i)
    {
        int result = playGame(&guesser1, &thinker1, &guesser2, &thinker2, 1);
        score += result;
        switch (result)
        {
        case P1_WIN:
            ++p1Wins;
            std::cerr << "+";
            break;
        case P2_WIN:
            ++p2Wins;
            std::cerr << "-";
            break;
        case DRAW:
            ++draws;
            std::cerr << "0";
            break;
        default:
            std::cerr << " Error! ";
        }
    }
    std::cerr << std::endl;

    std::cout << "Final score: " << score << std::endl;
    std::cout << "Player 1 wins: " << p1Wins << std::endl;
    std::cout << "Player 2 wins: " << p2Wins << std::endl;
    std::cout << "Draws: " << draws << std::endl;

    /*for (int i = 0; i < 20; ++i)
    {
        int result = playRound(&guesser1, &thinker2, 1);
        switch (result)
        {
        case G_FAIL:
            std::cout << "The guesser failed to guess the number." << std::endl;
            break;
        case T_FAIL:
            std::cout << "The thinker played incorrectly." << std::endl;
            break;
        default:
            std::cout << "The guesser took " << result << " guesses." << std::endl;
        }
    }*/

    return 0;
}
