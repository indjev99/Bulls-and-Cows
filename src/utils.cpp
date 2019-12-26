#include "utils.h"
#include "params.h"
#include "number_range.h"
#include <unordered_map>
#include <algorithm>
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
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        if (dig == 0 && i == NUM_DIGS - 1) return false;
        if (used[dig]) return false;
        used[dig] = true;
    }
    if (number > 0) return false;
    return true;
}

static int numberCodeMap[POS_NUMS];
static std::vector<int> findAllValidNumbers()
{
    std::vector<int> validNumbers;
    for (int i = MIN_NUM; i <= MAX_NUM; ++i)
    {
        if (isNumberValid(i))
        {
            numberCodeMap[i - MIN_NUM] = validNumbers.size();
            validNumbers.push_back(i);
        }
    }
    return validNumbers;
}
const std::vector<int> validNumbers = findAllValidNumbers();

int numberToIndex(int number)
{
    return numberCodeMap[number - MIN_NUM];
}

bool isResponseValid(Response response)
{
    int b = response.bulls;
    int c = response.cows;
    return b >= 0 && c >= 0 && b + c <= NUM_DIGS && (b != NUM_DIGS - 1 || c != 1);
}

bool isResponseFinal(Response response)
{
    return response.bulls == NUM_DIGS;
}

Response findResponse(int number, int guess)
{
    bool used[BASE];
    int digs[NUM_DIGS];
    for (int i = 0; i < BASE; ++i)
    {
        used[i] = false;
    }
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        int dig = number % BASE;
        number /= BASE;
        used[dig] = true;
        digs[i] = dig;
    }
    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        int dig = guess % BASE;
        guess /= BASE;
        if (digs[i] == dig) ++bulls;
        else if (used[dig]) ++cows;
    }
    return {bulls, cows};
}

static int responseCodeMap[NUM_DIGS + 1][NUM_DIGS + 1];
static std::vector<Response> findAllValidResponses()
{
    std::vector<Response> validResponses;
    for (int i = 0; i < (NUM_DIGS + 1) * (NUM_DIGS + 1); ++i)
    {
        int bulls = i / (NUM_DIGS + 1);
        int cows = i % (NUM_DIGS + 1);
        if (isResponseValid({bulls, cows}))
        {
            responseCodeMap[bulls][cows] = validResponses.size();
            validResponses.push_back({bulls, cows});
        }
    }
    return validResponses;
}
const std::vector<Response> validResponses = findAllValidResponses();

int responseToIndex(Response response)
{
    return responseCodeMap[response.bulls][response.cows];
}

std::vector<int> findDigits(int number)
{
    std::vector<int> digits;
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        digits.push_back(number % BASE);
        number /= BASE;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

int findNumber(const std::vector<int>& digits)
{
    int number = 0;
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        number = number * BASE + digits[i];
    }
    return number;
}

static std::vector<int> findAllValidDigits()
{
    std::vector<int> validDigits;
    for (int i = 0; i < BASE; ++i)
    {
        validDigits.push_back(i);
    }
    return validDigits;
}
const std::vector<int> validDigits = findAllValidDigits();

static std::vector<int> findAllValidPos()
{
    std::vector<int> validPos;
    for (int i = 0; i < NUM_DIGS; ++i)
    {
        validPos.push_back(i);
    }
    return validPos;
}
const std::vector<int> validPos = findAllValidPos();

int randomNumber()
{
    int rng = rand() * (RAND_MAX + 1) + rand();
    return validNumbers[rng % validNumbers.size()];
}

void initRandomizer()
{
    srand(time(0));
}
