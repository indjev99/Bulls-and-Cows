#ifndef TRACKER_GUESSER_H_INCLUDED
#define TRACKER_GUESSER_H_INCLUDED

#include "guesser.h"
#include "valid_tracker.h"
#include "symmetry_tracker.h"

struct TrackerGuesser : Guesser
{
    void reset() final;
    int makeGuess(int guess, Response response) final;

protected:
    int turn;
    ValidTracker vtracker;
    SymmetryTracker stracker;

    virtual int decideGuess() const =0;
};

#endif // TRACKER_GUESSER_H_INCLUDED
