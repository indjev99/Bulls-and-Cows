#ifndef TRACKER_THINKER_H_INCLUDED
#define TRACKER_THINKER_H_INCLUDED

#include "thinker.h"
#include "tracker.h"

struct TrackerThinker : Thinker
{
    void reset() final;
    Response getResponse(int guess) final;

protected:
    int turn;
    Tracker tracker;

    virtual Response decideResponse(int guess) =0;
};

#endif // TRACKER_THINKER_H_INCLUDED
