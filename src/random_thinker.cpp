#include "random_thinker.h"
#include "utils.h"

void RandomThinker::reset()
{
    number = randomNumber();
}

Response RandomThinker::getResponse(int guess)
{
    return findResponse(number, guess);
}

int RandomThinker::getNumber()
{
    return number;
}
