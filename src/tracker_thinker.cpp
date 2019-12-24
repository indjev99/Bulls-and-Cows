#include "tracker_thinker.h"

void TrackerThinker::reset()
{
    _turn = 0;
    _tracker.reset();
}

Response TrackerThinker::getResponse(int guess)
{
    ++_turn;
    Response response = decideResponse(guess);
    _tracker.update(guess, response);
    return response;
}
