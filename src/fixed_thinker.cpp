#include "fixed_thinker.h"
#include "utils.h"

void FixedThinker::reset() {}

Response FixedThinker::getResponse(int guess)
{
    return findResponse(number, guess);
}

int FixedThinker::getNumber()
{
    return number;
}

void FixedThinker::setNumber(int number)
{
    this->number = number;
}
