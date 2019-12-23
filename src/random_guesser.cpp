#include "random_guesser.h"
#include "utils.h"

void RandomGuesser::reset() {}

int RandomGuesser::makeGuess(int guess, const Response& response)
{
    return randomNumber();
}
