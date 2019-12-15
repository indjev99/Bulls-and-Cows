#include "play.h"
#include "utils.h"
#include <vector>

struct Exchange
{
    int guess;
    Response response;

    Exchange(int guess, const Response& response):
        guess(guess),
        response(response) {};
    bool checkValid(int number) const
    {
        Response correct = findResponse(number, guess);
        return response.bulls == correct.bulls && response.cows == correct.cows;
    }
};

int play(Guesser* guesser, Thinker* thinker, int maxGuesses)
{
    guesser->reset();
    thinker->reset();

    std::vector<Exchange> exchanges;
    int numGuesses = 0;
    Response response = {0, 0};
    while (!isResponseFinal(response) && numGuesses < maxGuesses)
    {
        ++numGuesses;
        int guess = guesser->makeGuess(response);
        if (!isNumberValid(guess)) return G_FAIL;
        response = thinker->getResponse(guess);
        if (!isResponseValid(response)) return T_FAIL;
        exchanges.push_back(Exchange(guess, response));
    }
    int number = thinker->getNumber();
    if (!isNumberValid(number)) return T_FAIL;
    for (const Exchange& exchange : exchanges)
    {
        if (!exchange.checkValid(number)) return T_FAIL;
    }
    if (!isResponseFinal(response)) return G_FAIL;
    return numGuesses;
}
