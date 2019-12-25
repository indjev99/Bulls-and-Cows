#ifndef LOOKAHEAD_GUESSER_H_INCLUDED
#define LOOKAHEAD_GUESSER_H_INCLUDED

#include "tracker_guesser.h"

struct LookaheadGuesser final : TrackerGuesser
{
protected:
    int decideGuess() override;
};

#endif // LOOKAHEAD_GUESSER_H_INCLUDED
