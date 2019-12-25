#ifndef USER_GUESSER_H_INCLUDED
#define USER_GUESSER_H_INCLUDED

#include "guesser.h"

struct UserGuesser final : Guesser
{
    void reset() override;
    int makeGuess(int guess, Response response) override;
};

#endif // USER_GUESSER_H_INCLUDED
