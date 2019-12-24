#ifndef RANDOM_GUESSER_H_INCLUDED
#define RANDOM_GUESSER_H_INCLUDED

#include "guesser.h"

struct RandomGuesser final : Guesser
{
    int makeGuess(int guess, const Response& response) override;
};

#endif // RANDOM_GUESSER_H_INCLUDED
