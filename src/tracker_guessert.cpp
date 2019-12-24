#include "tracker_guesser.h"

void TrackerGuesser::reset()
{
    turn = 0;
    tracker.reset();
}

int TrackerGuesser::makeGuess(int guess, const Response& response)
{
    ++turn;
    if (turn > 1) tracker.update(guess, response);
    if (tracker.numValid() == 1) return tracker.oneValid();
    return decideGuess();
}
