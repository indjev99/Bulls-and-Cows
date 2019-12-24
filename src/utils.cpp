#include "utils.h"
#include "params.h"
#include <unordered_map>
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
    int number;
    do
    {
        int rng = rand() * (RAND_MAX + 1) + rand();
        number = rng % POS_NUMS + MIN_NUM;
    }
    while (!isNumberValid(number));
    return number;
}

void initRandomizer()
{
    srand(time(0));
}

static int codeMap[DIGS + 1][DIGS + 1];

static std::vector<Response> findAllValidResponses()
{
    std::vector<Response> validResponses;
    for (int i = 0; i < (DIGS + 1) * (DIGS + 1); ++i)
    {
        int bulls = i / (DIGS + 1);
        int cows = i % (DIGS + 1);
        if (isResponseValid({bulls, cows}))
        {
            codeMap[bulls][cows] = validResponses.size();
            validResponses.push_back({bulls, cows});
        }
    }
    return validResponses;
}

const std::vector<Response> validResponses = findAllValidResponses();

int responseToCode(const Response& response)
{
    return codeMap[response.bulls][response.cows];
}
