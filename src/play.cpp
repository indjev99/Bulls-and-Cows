#include "play.h"
#include "utils.h"
#include "tracker.h"
#include <chrono>

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
        using seconds = std::chrono::duration<double, std::ratio<1, 1>>;
        time += seconds(endTimePoint - startTimePoint).count();
    }

protected:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint, endTimePoint;
};

#include <iostream>
using namespace std;

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
    Tracker tracker;
    tracker.reset();
    while (!isResponseFinal(response) && numGuesses < maxGuesses)
    {
        ++numGuesses;

        gTimer.start();
        int guess = guesser->makeGuess(response);
        gTimer.stop();
        if (!isNumberValid(guess) || gTimer.time > timeLimit) return G_FAIL;

        tTimer.start();
        response = thinker->getResponse(guess);
        tTimer.stop();
        tracker.update(guess, response);
        if (!isResponseValid(response) || tracker.numValid() == 0 || tTimer.time > timeLimit) return T_FAIL;
    }
    if (!isResponseFinal(response)) return G_FAIL;
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
