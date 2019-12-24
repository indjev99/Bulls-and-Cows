#ifndef GREEDY_GUESSER_H_INCLUDED
#define GREEDY_GUESSER_H_INCLUDED

#include "tracker_guesser.h"

struct GreedyGuesser final : TrackerGuesser
{
protected:
    int decideGuess();
};

#endif // GREEDY_GUESSER_H_INCLUDED
