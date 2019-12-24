#include "valid_guesser.h"
#include "utils.h"

int ValidGuesser::decideGuess()
{
    return tracker.oneValid();
}
