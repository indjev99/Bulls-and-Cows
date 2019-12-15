#include "utils.h"
#include "play.h"
#include "random_guesser.h"
#include "random_thinker.h"
#include <iostream>

int main()
{
    initRandomizer();

    RandomGuesser guesser;
    RandomThinker thinker;

    for (int i = 0; i < 20; ++i)
    {
        int result = play(&guesser, &thinker);
        switch (result)
        {
        case G_FAIL:
            std::cout << "The guesser failed to guess the number." << std::endl;
            break;
        case T_FAIL:
            std::cout << "The thinker played incorrectly." << std::endl;
            break;
        default:
            std::cout << "The guesser took " << result << " guesses." << std::endl;
        }
    }

    return 0;
}
