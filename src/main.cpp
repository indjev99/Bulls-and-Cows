#include "random_guesser.h"
#include "dummy_guesser.h"
#include "valid_guesser.h"
#include "greedy_guesser.h"
#include "lookahead_guesser.h"
#include "random_thinker.h"
#include "valid_thinker.h"
#include "greedy_thinker.h"
#include "lookahead_thinker.h"
#include "games.h"
#include "utils.h"

int main()
{
    initRandomizer();

    DummyGuesser guesser1;
    ValidGuesser guesser2;
    GreedyGuesser guesser3;
    LookaheadGuesser guesser4;

    RandomThinker thinker1;
    ValidThinker thinker2;
    GreedyThinker thinker3;
    LookaheadThinker thinker4;

    /*profile(&guesser1, &thinker4, 1, 500);
    profile(&guesser2, &thinker4, 1, 500);
    profile(&guesser3, &thinker4, 1, 500);
    profile(&guesser4, &thinker4, 1, 500);*/

    battle(&guesser4, &thinker3, &guesser3, &thinker3, 1, 1000, true);

    battle(&guesser4, &thinker4, &guesser3, &thinker4, 1, 1000, true);

    return 0;
}
