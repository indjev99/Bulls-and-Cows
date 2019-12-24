#ifndef RANDOM_THINKER_H_INCLUDED
#define RANDOM_THINKER_H_INCLUDED

#include "fixed_thinker.h"

struct RandomThinker final : FixedThinker
{
    void reset() override;
};

#endif // RANDOM_THINKER_H_INCLUDED
