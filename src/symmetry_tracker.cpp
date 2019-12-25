#include "symmetry_tracker.h"
#include "utils.h"
#include <algorithm>

void SymmetryTracker::reset()
{
    turn = 0;
    unasked.clear();
    std::vector<int> permutation(validDigits.begin(), validDigits.end());
    std::random_shuffle(permutation.begin(), permutation.end());
    std::copy(permutation.begin(), permutation.end(), std::inserter(unasked, unasked.begin()));
    unasked.erase(0);
    firstAsked.clear();
}

void SymmetryTracker::update(int guess)
{
    ++turn;
    for (int digit : findDigits(guess))
    {
        unasked.erase(digit);
        if (turn == 1 && digit != 0) firstAsked.insert(digit);
    }
}

SymmetryTracker SymmetryTracker::afterUpdate(int guess) const
{
    SymmetryTracker tracker;
    tracker = *this;
    tracker.update(guess);
    return tracker;
}

std::vector<int> SymmetryTracker::reduce(const std::unordered_set<int>& numbers) const
{
    std::vector<int> reduced;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(reduced), [this](int num){return isUnique(num);});
    return reduced;
}

std::vector<int> SymmetryTracker::reduce(const std::vector<int>& numbers) const
{
    std::vector<int> reduced;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(reduced), [this](int num){return isUnique(num);});
    return reduced;
}

bool SymmetryTracker::isUnique(int number) const
{
    std::unordered_set<int>::const_iterator uIt = unasked.begin();
    int pos = 0;
    int lastFask = 0;
    int numFask = 0;
    for (int digit : findDigits(number))
    {
        if (unasked.find(digit) != unasked.end() && digit != *uIt++) return false;
        else if (turn == 1)
        {
            std::unordered_set<int>::const_iterator it = firstAsked.find(digit);
            if (it != firstAsked.end())
            {
                int dist = std::distance(firstAsked.begin(), it);
                lastFask = std::max(lastFask, dist + 1);
                ++numFask;
            }
        }
        else if (turn == 0 && digit == 0 && pos > 0) return false;
        ++pos;
    }
    if (numFask < lastFask) return false;
    return true;
}
