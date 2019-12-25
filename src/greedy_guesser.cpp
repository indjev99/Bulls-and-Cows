#include "greedy_guesser.h"
#include "utils.h"

int GreedyGuesser::decideGuess() const
{
    int bestValue = vtracker.numValid();
    int bestGuess = 0;
    for (int guess : stracker.reduce(validNumbers))
    {
        int value = vtracker.worstSplitSize(guess);
        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }
    return bestGuess;
}
