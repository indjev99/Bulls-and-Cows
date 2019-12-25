#include "tracker_thinker.h"

void TrackerThinker::reset()
{
    turn = 0;
    vtracker.reset();
    stracker.reset();
}

Response TrackerThinker::getResponse(int guess)
{
    ++turn;
    stracker.update(guess);
    Response response = decideResponse(guess);
    vtracker.update(guess, response);
    return response;
}
