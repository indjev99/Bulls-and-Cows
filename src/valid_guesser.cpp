#include "valid_guesser.h"

int ValidGuesser::decideGuess() const
{
    return vtracker.oneValid();
}
