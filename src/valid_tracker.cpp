#include "valid_tracker.h"
#include "utils.h"
#include <algorithm>

void ValidTracker::reset()
{
    valid.clear();
    std::vector<int> permutation(validNumbers.begin(), validNumbers.end());
    std::random_shuffle(permutation.begin(), permutation.end());
    std::copy(permutation.begin(), permutation.end(), std::inserter(valid, valid.begin()));
}

int ValidTracker::numValid() const
{
    return valid.size();
}

int ValidTracker::oneValid() const
{
    return *valid.begin();
}

int ValidTracker::otherValid() const
{
    return *++valid.begin();
}

const std::unordered_set<int>& ValidTracker::allValid() const
{
    return valid;
}

bool ValidTracker::isValid(int number) const
{
    return valid.find(number) != valid.end();
}

static bool validCondition(int number, int guess, const Response& response)
{
    Response correct = findResponse(number, guess);
    return correct.bulls == response.bulls && correct.cows == response.cows;
}

void ValidTracker::update(int guess, Response response)
{
    std::unordered_set<int>::iterator it = valid.begin();
    while (it != valid.end())
	{
		if (!validCondition(*it, guess, response)) it = valid.erase(it);
		else it++;
	}
}

int ValidTracker::numValidAfterUpdate(int guess, Response response) const
{
    int cnt = 0;
    for (int num : valid)
    {
        if (validCondition(num, guess, response)) ++cnt;
    }
    return cnt;
}

ValidTracker ValidTracker::afterUpdate(int guess, Response response) const
{
    ValidTracker tracker;
    for (int num : valid)
    {
        if (validCondition(num, guess, response)) tracker.valid.insert(num);
    }
    return tracker;
}

int ValidTracker::worstSplitSize(int guess) const
{
    std::vector<int> cnts(validResponses.size());
    for (int number : valid)
    {
        ++cnts[responseToIndex(findResponse(number, guess))];
    }
    return *std::max_element(cnts.begin(), cnts.end());
}

std::vector<ValidTracker> ValidTracker::split(int guess) const
{
    std::vector<ValidTracker> splits(validResponses.size());
    for (int number : valid)
    {
        splits[responseToIndex(findResponse(number, guess))].valid.insert(number);
    }
    return splits;
}
