#include "random_guesser.h"
#include "utils.h"

void RandomGuesser::reset() {}

int RandomGuesser::makeGuess(const Response& response)
{
    return randomNumber();
}
