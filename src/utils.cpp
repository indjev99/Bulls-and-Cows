#include "utils.h"
#include <algorithm>
#include <stdlib.h>
#include <time.h>

static const int BASE = 10;
static int NUM_DIGITS;

static int tempDigits[BASE];
static bool tempUsed[BASE];

bool isNumberValid(int number)
{
    if (number < 0) return false;
    std::fill(tempUsed, tempUsed + BASE, false);
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        if (dig == 0 && i == NUM_DIGITS - 1) return false;
        if (tempUsed[dig]) return false;
        tempUsed[dig] = true;
    }
    if (number > 0) return false;
    return true;
}

bool isResponseValid(Response response)
{
    int b = response.bulls;
    int c = response.cows;
    return b >= 0 && c >= 0 && b + c <= NUM_DIGITS && (b != NUM_DIGITS - 1 || c != 1);
}

bool isResponseFinal(Response response)
{
    return response.bulls == NUM_DIGITS;
}

Response findResponse(int number, int guess)
{
    std::fill(tempUsed, tempUsed + BASE, false);
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        tempUsed[dig] = true;
        tempDigits[i] = dig;
    }
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        int dig = guess % BASE;
        guess /= BASE;
        if (tempDigits[i] == dig) ++bulls;
        else if (tempUsed[dig]) ++cows;
    }
    return {bulls, cows};
}

std::vector<int> findDigits(int number)
{
    std::vector<int> digits(NUM_DIGITS);
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        digits[NUM_DIGITS - i - 1] = number % BASE;
        number /= BASE;
    }
    return digits;
}

int findNumber(const std::vector<int>& digits)
{
    int number = 0;
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        number = number * BASE + digits[i];
    }
    return number;
}

std::vector<int> validNumbers;
std::vector<Response> validResponses;
std::vector<int> validDigits;
std::vector<int> validPos;

static int responseCodeMap[BASE + 1][BASE + 1];

static void findAllValidNumbers()
{
    validNumbers.clear();
    int maxNum = 1;
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        maxNum *= BASE;
    }
    for (int i = 0; i <= maxNum; ++i)
    {
        if (isNumberValid(i)) validNumbers.push_back(i);
    }
}

static void findAllValidResponses()
{
    validResponses.clear();
    for (int bulls = 0; bulls <= NUM_DIGITS; ++bulls)
    {
        for (int cows = 0; cows <= NUM_DIGITS; ++cows)
        {
            if (isResponseValid({bulls, cows}))
            {
                responseCodeMap[bulls][cows] = validResponses.size();
                validResponses.push_back({bulls, cows});
            }
        }
    }
}

static void findAllValidDigits()
{
    validDigits.clear();
    for (int i = 0; i < BASE; ++i)
    {
        validDigits.push_back(i);
    }
}

static void findAllValidPos()
{
    validPos.clear();
    for (int i = 0; i < NUM_DIGITS; ++i)
    {
        validPos.push_back(i);
    }
}

int responseToIndex(Response response)
{
    return responseCodeMap[response.bulls][response.cows];
}

int randomNumber()
{
    int rng = rand() * (RAND_MAX + 1) + rand();
    return validNumbers[rng % validNumbers.size()];
}

void initRandomizer()
{
    srand(time(0));
}

void setParams(int numDigits)
{
    NUM_DIGITS = numDigits;

    findAllValidNumbers();
    findAllValidResponses();
    findAllValidDigits();
    findAllValidPos();
}
