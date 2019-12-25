#include "random_guesser.h"
#include "dummy_guesser.h"
#include "valid_guesser.h"
#include "greedy_guesser.h"
#include "lookahead_guesser.h"
#include "user_guesser.h"
#include "random_thinker.h"
#include "valid_thinker.h"
#include "greedy_thinker.h"
#include "lookahead_thinker.h"
#include "user_thinker.h"
#include "games.h"
#include "play.h"
#include "utils.h"
#include <iostream>

DummyGuesser guesser1;
ValidGuesser guesser2;
GreedyGuesser guesser3;
LookaheadGuesser guesser4;
UserGuesser guesserU;

RandomThinker thinker1;
ValidThinker thinker2;
GreedyThinker thinker3;
LookaheadThinker thinker4;
UserThinker thinkerU;

std::vector<Guesser*> guessers = {&guesser1, &guesser2, &guesser3, &guesser4};
std::vector<Thinker*> thinkers = {&thinker1, &thinker2, &thinker3, &thinker4};

void userGuess()
{
    int diff = 0;
    while (diff < 1 || diff > 4)
    {
        std::cout << "Select difficulty (1 - 4): ";
        std::cin >> diff;
    }
    profile(&guesserU, thinkers[diff - 1], -1, 1, 2);
}

void userThink()
{
    int diff = 0;
    while (diff < 1 || diff > 4)
    {
        std::cout << "Select difficulty (1 - 4): ";
        std::cin >> diff;
    }
    profile(guessers[diff], &thinkerU, -1, 1, 2);
}

void shell()
{
    char choice = ' ';
    while (true)
    {
        std::cout << "Do you want to guess or think (g / t)? ";
        std::cin >> choice;
        switch (choice)
        {
        case 'g':
            userGuess();
            break;
        case 't':
            userThink();
            break;
        }
    }
}

int main()
{
    initRandomizer();

    shell();

    //battle(&guesser4, &thinker3, &guesser3, &thinker3, 30, 1000, true);

    return 0;
}
