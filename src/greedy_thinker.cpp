#include "greedy_thinker.h"
#include "utils.h"

Response GreedyThinker::decideResponse(int guess) const
{
    int bestValue = 0;
    Response bestResponse;
    for (const Response& response : validResponses)
    {
        int value = vtracker.numValidAfterUpdate(guess, response);
        if (value > bestValue)
        {
            bestValue = value;
            bestResponse = response;
        }
    }

    return bestResponse;
}
