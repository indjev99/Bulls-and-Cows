#ifndef DUMMY_GUESSER_H_INCLUDED
#define DUMMY_GUESSER_H_INCLUDED

#include "tracker_guesser.h"

struct DummyGuesser final : TrackerGuesser
{
protected:
    int decideGuess();
};

#endif // DUMMY_GUESSER_H_INCLUDED
