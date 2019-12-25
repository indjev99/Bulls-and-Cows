#include "lookahead_thinker.h"
#include "utils.h"

Response LookaheadThinker::decideResponse(int guess)
{
    std::pair<int, int> bestValue = {0, 0};
    Response bestResponse;
    for (const Response& response : validResponses)
    {
        Tracker currTracker = tracker.afterUpdate(guess, response);
        std::pair<int, int> value = {currTracker.numValid(), currTracker.numValid()};
        for (int guess : currTracker.allValid())
        {
            int currValue = currTracker.worstSplitSize(guess);
            value.first = std::min(value.first, currValue);
        }
        if (value > bestValue)
        {
            bestValue = value;
            bestResponse = response;
        }
    }

    return bestResponse;
}
