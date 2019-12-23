#include "random_guesser.h"
#include "random_thinker.h"
#include "games.h"
#include "utils.h"

int main()
{
    initRandomizer();

    RandomGuesser guesser1;
    RandomThinker thinker1;

    RandomGuesser guesser2;
    RandomThinker thinker2;

    profile(&guesser1, 1);
    battle(&guesser1, &thinker1, &guesser2, &thinker2, 1, 1000, true);

    return 0;
}
