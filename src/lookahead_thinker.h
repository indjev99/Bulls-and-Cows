#ifndef LOOKAHEAD_THINKER_H_INCLUDED
#define LOOKAHEAD_THINKER_H_INCLUDED

#include "tracker_thinker.h"

struct LookaheadThinker final : TrackerThinker
{
protected:
    Response decideResponse(int guess) override;
};

#endif // LOOKAHEAD_THINKER_H_INCLUDED
