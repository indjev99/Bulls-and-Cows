#ifndef THINKER_H_INCLUDED
#define THINKER_H_INCLUDED

#include "response.h"

struct Thinker
{
    virtual void reset() = 0;
    virtual Response getResponse(int guess) = 0;
};

#endif // THINKER_H_INCLUDED
