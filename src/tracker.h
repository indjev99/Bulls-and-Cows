#ifndef TRACKER_H_INCLUDED
#define TRACKER_H_INCLUDED

#include "response.h"
#include <unordered_set>
#include <vector>

struct Tracker
{
    void reset();
    int numValid() const;
    int oneValid() const;
    int otherValid() const;
    const std::unordered_set<int>& allValid() const;
    bool isValid(int number) const;
    void update(int guess, const Response& response);
    int numValidAfterUpdate(int guess, const Response& response) const;
    Tracker afterUpdate(int guess, const Response& response) const;
    int worstSplitSize(int guess) const;
    std::vector<Tracker> split(int guess) const;

protected:
    std::unordered_set<int> valid;
};

#endif // TRACKER_H_INCLUDED
