#include "lookahead_guesser.h"

int LookaheadGuesser::decideGuess()
{
    if (turn == 1) return tracker.oneValid();

    if (turn == 2)
    {
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

    std::pair<int, int> bestValue = {tracker.numValid(), tracker.numValid()};
    int bestGuess = 0;
    for (int guess : tracker.allValid())
    {
        std::pair<int, int> value = {0, 0};
        std::vector<Tracker> splits = tracker.split(guess);
        for (const Tracker& currTracker : splits)
        {
            int currBestValue = currTracker.numValid();
            for (int guess : currTracker.allValid())
            {
                int currValue = currTracker.worstSplitSize(guess);
                currBestValue = std::min(currBestValue, currValue);
            }
            value.first = std::max(value.first, currBestValue);
            value.second =  std::max(value.second, currTracker.numValid());
        }
        if (value < bestValue)
        {
            bestValue = value;
            bestGuess = guess;
        }
    }

    return bestGuess;
}
