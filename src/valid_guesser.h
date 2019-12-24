#ifndef VALID_GUESSER_H_INCLUDED
#define VALID_GUESSER_H_INCLUDED

#include "tracker_guesser.h"

struct ValidGuesser final : TrackerGuesser
{
protected:
    int decideGuess() override;
};

#endif // VALID_GUESSER_H_INCLUDED
