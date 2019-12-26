#ifndef VALID_TRACKER_H_INCLUDED
#define VALID_TRACKER_H_INCLUDED

#include "response.h"
#include <unordered_set>
#include <vector>

struct ValidTracker
{
    void reset();
    int numValid() const;
    int oneValid() const;
    int otherValid() const;
    const std::unordered_set<int>& allValid() const;
    bool isValid(int number) const;
    void update(int guess, Response response);
    int numValidAfterUpdate(int guess, Response response) const;
    ValidTracker afterUpdate(int guess, Response response) const;
    int worstSplitSize(int guess) const;
    std::vector<ValidTracker> split(int guess) const;

private:
    std::unordered_set<int> valid;
};

#endif // VALID_TRACKER_H_INCLUDED
