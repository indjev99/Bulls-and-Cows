#ifndef FIXED_THINKER_H_INCLUDED
#define FIXED_THINKER_H_INCLUDED

#include "thinker.h"

struct FixedThinker : Thinker
{
    void reset();
    Response getResponse(int guess);
    int getNumber();

    void setNumber(int number);

protected:
    int number;
};

#endif // FIXED_THINKER_H_INCLUDED
