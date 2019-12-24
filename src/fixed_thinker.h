#ifndef FIXED_THINKER_H_INCLUDED
#define FIXED_THINKER_H_INCLUDED

#include "thinker.h"

struct FixedThinker : Thinker
{
    Response getResponse(int guess) final;

    void setNumber(int number);

private:
    int number;
};

#endif // FIXED_THINKER_H_INCLUDED
