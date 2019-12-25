#ifndef GREEDY_THINKER_H_INCLUDED
#define GREEDY_THINKER_H_INCLUDED

#include "tracker_thinker.h"

struct GreedyThinker final : TrackerThinker
{
protected:
    Response decideResponse(int guess) const override;
};

#endif // GREEDY_THINKER_H_INCLUDED
