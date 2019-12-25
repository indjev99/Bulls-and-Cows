#include "valid_thinker.h"
#include "utils.h"

Response ValidThinker::decideResponse(int guess) const
{
    int number = vtracker.oneValid();
    if (number == guess && vtracker.numValid() > 1) number = vtracker.otherValid();
    return findResponse(number, guess);
}
