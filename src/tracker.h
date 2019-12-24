#ifndef TRACKER_H_INCLUDED
#define TRACKER_H_INCLUDED

#include "response.h"
#include <unordered_set>

struct Tracker
{
    void reset();
    int numValid() const;
    int oneValid() const;
    const std::unordered_set<int>& allValid() const;
    bool isValid(int number) const;
    void update(int guess, const Response& response);
    int numValidAfterUpdate(int guess, const Response& response) const;
    int split(int guess) const;

protected:
    std::unordered_set<int> valid;
};

#endif // TRACKER_H_INCLUDED
