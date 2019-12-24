#include "greedy_guesser.h"
#include "params.h"

int GreedyGuesser::decideGuess()
{
    if (turn == 1) return 1234;

    int bestValue = POS_NUMS;
    int bestGuess = 0;
    for (int guess : tracker.allValid())
    {
        int value = tracker.split(guess);
        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }

    return bestGuess;
}
