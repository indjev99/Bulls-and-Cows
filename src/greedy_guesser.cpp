#include "greedy_guesser.h"

int GreedyGuesser::decideGuess()
{
    if (turn == 1) return tracker.oneValid();

    int bestValue = tracker.numValid();
    int bestGuess = 0;
    for (int guess : tracker.allValid())
    {
        int value = tracker.worstSplitSize(guess);
        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }

    return bestGuess;
}
