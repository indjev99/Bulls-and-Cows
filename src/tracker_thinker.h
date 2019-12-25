#ifndef TRACKER_THINKER_H_INCLUDED
#define TRACKER_THINKER_H_INCLUDED

#include "thinker.h"
#include "valid_tracker.h"
#include "symmetry_tracker.h"

struct TrackerThinker : Thinker
{
    void reset() final;
    Response getResponse(int guess) final;

protected:
    int turn;
    ValidTracker vtracker;
    SymmetryTracker stracker;

    virtual Response decideResponse(int guess) const =0;
};

#endif // TRACKER_THINKER_H_INCLUDED
