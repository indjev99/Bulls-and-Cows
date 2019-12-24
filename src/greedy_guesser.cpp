#include "greedy_guesser.h"
#include "utils.h"

int GreedyGuesser::decideGuess()
{
    if (turn == 1) return randomNumber();

    int bestValue = tracker.numValid();
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
