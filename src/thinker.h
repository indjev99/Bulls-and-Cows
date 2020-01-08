#ifndef THINKER_H_INCLUDED
#define THINKER_H_INCLUDED

#include "response.h"

struct Thinker
{
    virtual void reset() {};
    virtual Response getResponse(int guess) = 0;
    virtual ~Thinker() = default;
};

#endif // THINKER_H_INCLUDED
