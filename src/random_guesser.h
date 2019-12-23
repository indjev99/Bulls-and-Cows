#ifndef RANDOM_GUESSER_H_INCLUDED
#define RANDOM_GUESSER_H_INCLUDED

#include "guesser.h"

struct RandomGuesser : Guesser
{
    void reset();
    int makeGuess(int guess, const Response& response);
};

#endif // RANDOM_GUESSER_H_INCLUDED
