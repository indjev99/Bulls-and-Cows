#ifndef PLAY_H_INCLUDED
#define PLAY_H_INCLUDED

#include "guesser.h"
#include "thinker.h"

#define G_FAILED -1
#define T_FAILED -2

int play(Guesser* guesser, Thinker* thinker);

#endif // PLAY_H_INCLUDED
