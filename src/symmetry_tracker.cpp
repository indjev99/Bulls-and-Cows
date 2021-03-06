#include "symmetry_tracker.h"
#include "utils.h"
#include <algorithm>
#include <unordered_map>

void SymmetryTracker::reset()
{
    turn = 0;
    unasked.clear();
    std::vector<int> permutation(validDigits.begin(), validDigits.end());
    std::random_shuffle(permutation.begin(), permutation.end());
    std::copy(permutation.begin(), permutation.end(), std::inserter(unasked, unasked.begin()));
    unasked.erase(0);
    zeroPos = -1;
    firstDigs.clear();
    firstPos.clear();
}

void SymmetryTracker::update(int guess)
{
    ++turn;
    int pos = 0;
    for (int digit : findDigits(guess))
    {
        unasked.erase(digit);
        if (turn == 1 && digit == 0) zeroPos = pos;
        if (turn == 1 && digit != 0)
        {
            firstDigs.push_back(digit);
            firstPos.push_back(pos);
        }
        ++pos;
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

static bool checkOrder(const std::vector<int>& elems, const std::unordered_set<int>& space)
{
    std::unordered_set<int>::const_iterator it = space.begin();
    for (int elem : elems)
    {
        if (space.find(elem) != space.end() && elem != *it++) return false;
    }
    return true;
}

static int num;

bool SymmetryTracker::isUnique(int number) const
{
    num = number;
    std::vector<int> digits = findDigits(number);
    if (!checkOrder(digits, unasked)) return false;

    if (turn == 0) return isUniqueTurn0(digits);
    else if (turn == 1) return isUniqueTurn1(digits);

    return true;
}

bool SymmetryTracker::isUniqueTurn0(const std::vector<int> digits) const
{
    int pos = 0;
    int last = digits.size() - 1;
    for (int digit : digits)
    {
        if (digit == 0 && pos != last) return false;
        ++pos;
    }
    return true;
}

bool SymmetryTracker::isUniqueTurn1(const std::vector<int> digits) const
{
    int pos = 0;
    int lastFdig = 0;
    int numFdig = 0;
    std::unordered_map<int, int> currPos;
    std::unordered_set<int> simplePos(validPos.begin(), validPos.end());
    simplePos.erase(0);
    simplePos.erase(zeroPos);
    std::vector<int> specialDigs = {digits[0]};
    if (zeroPos >=0) specialDigs.push_back(digits[zeroPos]);
    bool bullFound = false;
    for (int digit : digits)
    {
        if (digit == 0) currPos[digit] = pos;
        else if (digit != 0)
        {
            std::vector<int>::const_iterator it = std::find(firstDigs.begin(), firstDigs.end(), digit);
            if (it != firstDigs.end())
            {
                currPos[digit] = pos;
                int dist = std::distance(firstDigs.begin(), it);
                simplePos.erase(firstPos[dist]);
                if (it != firstDigs.begin())
                {
                    lastFdig = std::max(lastFdig, dist);
                    ++numFdig;
                    if (!bullFound && firstPos[dist] == pos)
                    {
                        bullFound = true;
                        specialDigs.push_back(digit);
                    }
                }
            }
        }
        ++pos;
    }
    if (lastFdig > numFdig) return false;

    std::vector<int> allPos;
    if (currPos.find(0) != currPos.end()) allPos.push_back(currPos[0]);
    for (int digit : firstDigs)
    {
        if (currPos.find(digit) != currPos.end()) allPos.push_back(currPos[digit]);
    }
    if (!checkOrder(allPos, simplePos)) return false;

    std::vector<int>::const_iterator it = firstDigs.begin() + 1;
    int cnt = 0;
    for (int elem : specialDigs)
    {
        if (std::find(firstDigs.begin() + 1, firstDigs.end(), elem) != firstDigs.end()) ++cnt;
        if (std::find(firstDigs.begin() + 1, firstDigs.end(), elem) != firstDigs.end() && elem != *it++) return false;
    }

    return true;
}
