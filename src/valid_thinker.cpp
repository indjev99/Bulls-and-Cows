#include "valid_thinker.h"
#include "utils.h"

Response ValidThinker::decideResponse(int guess)
{
    int number = tracker.oneValid();
    if (number == guess && tracker.numValid() > 1) number = tracker.otherValid();
    return findResponse(number, guess);
}
