#ifndef TRACKER_GUESSER_H_INCLUDED
#define TRACKER_GUESSER_H_INCLUDED

#include "guesser.h"
#include "tracker.h"

struct TrackerGuesser : Guesser
{
    void reset() final;
    int makeGuess(int guess, const Response& response) final;

protected:
    int turn;
    Tracker tracker;

    virtual int decideGuess() =0;
};

#endif // TRACKER_GUESSER_H_INCLUDED
