#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "guesser.h"
#include "thinker.h"

const int G_FAIL = -1e9;
const int T_FAIL = 1e9;

const int P1_WIN = 1;
const int P2_WIN = -1;
const int DRAW = 0;

int playRound(Guesser* guesser, Thinker* thinker, double timeLimit, int maxGuesses=10000);
int playGame(Guesser* guesser1, Thinker* thinker1, Guesser* guesser2, Thinker* thinker2, double timeLimit, int maxGuesses=10000);

#endif // PLAY_H_INCLUDED
