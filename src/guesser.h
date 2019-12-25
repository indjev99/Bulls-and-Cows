#ifndef GUESSER_H_INCLUDED
#define GUESSER_H_INCLUDED

#include "response.h"

struct Guesser
{
    virtual void reset() {};
    virtual int makeGuess(int guess, Response response) = 0;
};

#endif // GUESSER_H_INCLUDED
