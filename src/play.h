#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "guesser.h"
#include "thinker.h"

#define G_FAIL -1
#define T_FAIL -2

int play(Guesser* guesser, Thinker* thinker, int maxGueses=10000);

#endif // PLAY_H_INCLUDED
