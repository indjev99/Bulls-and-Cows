#ifndef TRACKER_GUESSER_H_INCLUDED
#define TRACKER_GUESSER_H_INCLUDED

#include "guesser.h"
#include "tracker.h"

struct TrackerGuesser : Guesser
{
    void reset() final;
    int makeGuess(int guess, const Response& response) final;

protected:
    const int& turn = _turn;
    const Tracker& tracker = _tracker;

    virtual int decideGuess() =0;

private:
    int _turn;
    Tracker _tracker;
};

#endif // TRACKER_GUESSER_H_INCLUDED
