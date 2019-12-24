#include "tracker_guesser.h"

void TrackerGuesser::reset()
{
    _turn = 0;
    _tracker.reset();
}

int TrackerGuesser::makeGuess(int guess, const Response& response)
{
    ++_turn;
    if (turn > 1) _tracker.update(guess, response);
    if (tracker.numValid() == 1) return tracker.oneValid();
    return decideGuess();
}
