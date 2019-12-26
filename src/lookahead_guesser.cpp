#include "lookahead_guesser.h"
#include "utils.h"

int LookaheadGuesser::decideGuess() const
{
    if (turn == 1 || turn >= 3)
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

    std::pair<int, int> bestValue = {vtracker.numValid(), vtracker.numValid()};
    int bestGuess = 0;
    for (int guess : stracker.reduce(validNumbers))
    {
        std::pair<int, int> value = {0, 0};
        std::vector<ValidTracker> splits = vtracker.split(guess);
        SymmetryTracker currStracker = stracker.afterUpdate(guess);
        for (const ValidTracker& currTracker : splits)
        {
            int currBestValue = currTracker.numValid();
            value.second = std::max(value.second, currBestValue);
            for (int i = 0; i < 25; ++i)
            {
                int currGuess = randomNumber();
                int currValue = currTracker.worstSplitSize(currGuess);
                currBestValue = std::min(currBestValue, currValue);
            }
            value.first = std::max(value.first, currBestValue);
        }
        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }
    return bestGuess;
}
