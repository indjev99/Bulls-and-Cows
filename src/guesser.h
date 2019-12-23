#ifndef GUESSER_H_INCLUDED
#define GUESSER_H_INCLUDED

#include "response.h"

struct Guesser
{
    virtual void reset() = 0;
    virtual int makeGuess(int guess, const Response& response) = 0;
};

#endif // GUESSER_H_INCLUDED
