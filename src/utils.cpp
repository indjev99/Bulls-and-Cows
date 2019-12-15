#include "utils.h"
#include "params.h"
#include <stdlib.h>
#include <time.h>

bool isNumberValid(int number)
{
    if (number < 0) return false;
    bool used[BASE];
    for (int i = 0; i < BASE; ++i)
    {
        used[i] = false;
    }
    for (int i = 0; i < DIGS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        if (dig == 0 && i == DIGS - 1) return false;
        if (used[dig]) return false;
        used[dig] = true;
    }
    if (number > 0) return false;
    return true;
}
bool isResponseValid(const Response& response)
{
    int b = response.bulls;
    int c = response.cows;
    return b >= 0 && c >= 0 && b + c <= DIGS && (b != DIGS - 1 || c != 1);
}
bool isResponseFinal(const Response& response)
{
    return response.bulls == DIGS;
}
Response findResponse(int number, int guess)
{
    bool used[BASE];
    int digs[DIGS];
    for (int i = 0; i < BASE; ++i)
    {
        used[i] = false;
    }
    for (int i = 0; i < DIGS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        used[dig] = true;
        digs[i] = dig;
    }
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < DIGS; ++i)
    {
        int dig = guess % BASE;
        guess /= BASE;
        if (digs[i] == dig) ++bulls;
        else if (used[dig]) ++cows;
    }
    return {bulls, cows};
}
int randomNumber()
{
    int poss = 1;
    int maxNumber = 1;
    for (int i = 0; i < DIGS; ++i)
    {
        poss *= i ? BASE : BASE - 1;
        maxNumber *= BASE;
    }
    --maxNumber;
    int number = 0;
    while (!isNumberValid(number))
    {
        int rng = rand() * (RAND_MAX + 1) + rand();
        number = maxNumber - rng % poss;
    }
    return number;
}
void initRandomizer()
{
    srand(time(0));
}
