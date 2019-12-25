#include "lookahead_guesser.h"
#include "utils.h"

#include <iostream>
using namespace std;

int LookaheadGuesser::decideGuess() const
{
    //if (turn == 1) cerr << endl;

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
        //cerr << turn << ". " << vtracker.numValid() << " = " << bestValue << endl;
        return bestGuess;
    }

    std::pair<int, int> bestValue = {vtracker.numValid(), vtracker.numValid()};
    int bestGuess = 0;
    for (int guess : stracker.reduce(validNumbers))
    {
        std::pair<int, int> value = {0, 0};
        value.first = vtracker.worstSplitSize(guess);

        std::vector<ValidTracker> splits = vtracker.split(guess);
        SymmetryTracker currStracker = stracker.afterUpdate(guess);
        for (const ValidTracker& currTracker : splits)
        {
            int currBestValue = currTracker.numValid();
            for (int i = 0; i < 100; ++i)
            {
                int currGuess = randomNumber();
                int currValue = currTracker.worstSplitSize(currGuess);
                currBestValue = std::min(currBestValue, currValue);
            }
            value.second = std::max(value.second, currBestValue);
        }

        std::swap(value.first, value.second);

        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }
    //cerr << turn << ". " << vtracker.numValid() << " = " << bestValue.second << " " << bestValue.first << endl;
    return bestGuess;
}
