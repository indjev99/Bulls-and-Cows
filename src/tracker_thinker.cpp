#include "tracker_thinker.h"

void TrackerThinker::reset()
{
    turn = 0;
    tracker.reset();
}

Response TrackerThinker::getResponse(int guess)
{
    ++turn;
    Response response = decideResponse(guess);
    tracker.update(guess, response);
    return response;
}
