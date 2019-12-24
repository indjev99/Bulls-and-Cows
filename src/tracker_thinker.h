#ifndef TRACKER_THINKER_H_INCLUDED
#define TRACKER_THINKER_H_INCLUDED

#include "thinker.h"
#include "tracker.h"

struct TrackerThinker : Thinker
{
    void reset() final;
    Response getResponse(int guess) final;

protected:
    const int& turn = _turn;
    const Tracker& tracker = _tracker;

    virtual Response decideResponse(int guess) =0;

private:
    int _turn;
    Tracker _tracker;
};

#endif // TRACKER_THINKER_H_INCLUDED
