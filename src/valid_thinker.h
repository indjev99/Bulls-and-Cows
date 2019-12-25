#ifndef VALID_THINKER_H_INCLUDED
#define VALID_THINKER_H_INCLUDED

#include "tracker_thinker.h"

struct ValidThinker final : TrackerThinker
{
protected:
    Response decideResponse(int guess) override;
};

#endif // VALID_THINKER_H_INCLUDED
