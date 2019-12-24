#include "fixed_thinker.h"
#include "utils.h"

Response FixedThinker::getResponse(int guess)
{
    return findResponse(number, guess);
}

void FixedThinker::setNumber(int number)
{
    this->number = number;
}
