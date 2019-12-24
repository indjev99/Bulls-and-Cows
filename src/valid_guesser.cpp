#include "valid_guesser.h"

int ValidGuesser::decideGuess()
{
    return tracker.oneValid();
}
