#include "random_guesser.h"
#include "dummy_guesser.h"
#include "valid_guesser.h"
#include "greedy_guesser.h"
#include "random_thinker.h"
#include "greedy_thinker.h"
#include "games.h"
#include "utils.h"

int main()
{
    initRandomizer();

    GreedyGuesser guesser1;
    RandomThinker thinker1;

    ValidGuesser guesser2;
    RandomThinker thinker2;

    battle(&guesser1, &thinker1, &guesser2, &thinker2, 1, 1000, true);
    //profile(&guesser1, 1);

    return 0;
}
