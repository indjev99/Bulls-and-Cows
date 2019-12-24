#include "tracker.h"
#include "params.h"
#include "utils.h"
#include <algorithm>

void Tracker::reset()
{
    valid.clear();
    for (int i = MIN_NUM; i <= MAX_NUM; ++i)
    {
        if (isNumberValid(i)) valid.insert(i);
    }
}

int Tracker::numValid()
{
    return valid.size();
}

int Tracker::oneValid()
{
    return *valid.begin();
}

const std::unordered_set<int>& Tracker::allValid()
{
    return valid;
}

bool Tracker::isValid(int number)
{
    return valid.find(number) != valid.end();
}

static bool validCondition(int number, int guess, const Response& response)
{
    Response correct = findResponse(number, guess);
    return correct.bulls == response.bulls && correct.cows == response.cows;
}

void Tracker::update(int guess, const Response& response)
{
    std::unordered_set<int>::iterator it = valid.begin();
    while (it != valid.end())
	{
		if (!validCondition(*it, guess, response)) it = valid.erase(it);
		else it++;
	}
}

int Tracker::numValidAfterUpdate(int guess, const Response& response)
{
    int cnt = 0;
    for (int num : valid)
    {
        if (validCondition(num, guess, response)) ++cnt;
    }
    return cnt;
}

int Tracker::split(int guess)
{
    std::vector<int> cnts(validResponses.size());
    for (int number : valid)
    {
        ++cnts[responseToCode(findResponse(number, guess))];
    }
    return *std::max_element(cnts.begin(), cnts.end());
}
