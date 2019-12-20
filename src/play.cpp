#include "play.h"
#include "utils.h"
#include <vector>
#include <chrono>

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

struct Timer
{
    double time = 0;

    void start()
    {
        startTimePoint = std::chrono::high_resolution_clock::now();
    }
    void stop()
    {
        endTimePoint = std::chrono::high_resolution_clock::now();
        time += (endTimePoint - startTimePoint).count();
    }

protected:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint, endTimePoint;
};

int playRound(Guesser* guesser, Thinker* thinker, double timeLimit, int maxGuesses)
{
    Timer gTimer;
    Timer tTimer;

    gTimer.start();
    guesser->reset();
    gTimer.stop();

    tTimer.start();
    thinker->reset();
    tTimer.stop();

    int numGuesses = 0;
    Response response = {0, 0};
    std::vector<Exchange> exchanges;
    while (!isResponseFinal(response) && numGuesses < maxGuesses)
    {
        ++numGuesses;

        gTimer.start();
        int guess = guesser->makeGuess(response);
        gTimer.stop();
        if (!isNumberValid(guess)) return G_FAIL;

        if (gTimer.time > timeLimit) break;

        tTimer.start();
        response = thinker->getResponse(guess);
        tTimer.stop();
        if (!isResponseValid(response) || tTimer.time > timeLimit) return T_FAIL;

        exchanges.push_back(Exchange(guess, response));
    }

    tTimer.start();
    int number = thinker->getNumber();
    tTimer.stop();
    if (!isNumberValid(number)) return T_FAIL;
    for (const Exchange& exchange : exchanges)
    {
        if (!exchange.checkValid(number)) return T_FAIL;
    }

    if (!isResponseFinal(response) || gTimer.time > timeLimit) return G_FAIL;

    return numGuesses;
}

int playGame(Guesser* guesser1, Thinker* thinker1, Guesser* guesser2, Thinker* thinker2, double timeLimit, int maxGuesses)
{
    int res1 = playRound(guesser1, thinker2, timeLimit, maxGuesses);
    int res2 = playRound(guesser2, thinker1, timeLimit, maxGuesses);
    if (res1 < res2) return 1;
    if (res1 > res2) return -1;
    return 0;
}
