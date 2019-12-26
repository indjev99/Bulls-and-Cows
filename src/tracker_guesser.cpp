#include "tracker_guesser.h"

void TrackerGuesser::reset()
{
    turn = 0;
    vtracker.reset();
    stracker.reset();
}

int TrackerGuesser::makeGuess(int guess, Response response)
{
    ++turn;
    if (turn > 1)
    {
        vtracker.update(guess, response);
        stracker.update(guess);
    }
    if (vtracker.numValid() == 1) return vtracker.oneValid();
    return decideGuess();
}
