#ifndef RANDOM_THINKER_H_INCLUDED
#define RANDOM_THINKER_H_INCLUDED

#include "thinker.h"

struct RandomThinker : Thinker
{
    void reset();
    Response getResponse(int guess);
    int getNumber();

protected:
    int number;
};

#endif // RANDOM_THINKER_H_INCLUDED
