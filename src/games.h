#ifndef GAMES_H_INCLUDED
#define GAMES_H_INCLUDED

#include "guesser.h"
#include "thinker.h"

void battle(Guesser* guesser1, Thinker* thinker1, Guesser* guesser2, Thinker* thinker2, double timeLimit, int numGames, bool verbose=false);
void profile(Guesser* guesser, double timeLimit, int numIterations=1);
void profile(Guesser* guesser, Thinker* thinker, double timeLimit, int numGames, bool verbose=false);
void single(Guesser* guesser, Thinker* thinker, double timeLimit);
void shell();

#endif // GAMES_H_INCLUDED
