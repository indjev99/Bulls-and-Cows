#include "tracker.h"
#include "params.h"
#include "utils.h"

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

inline static bool validCondition(int number, int guess, const Response& response)
{
    Response correct = findResponse(number, guess);
    return correct.bulls == response.bulls && correct.cows == response.cows;
}

void Tracker::update(int guess, const Response& response)
{
    std::unordered_set<int>::iterator it = valid.begin();
    while(it != valid.end())
	{
		if (!validCondition(*it, guess, response)) it = valid.erase(it);
		else it++;
	}
    /*for (int num : valid)
    {
        Response correct = findResponse(num, guess);
        if (correct.bulls != response.bulls || correct.cows != response.cows) valid.erase(num);
    }*/
}
