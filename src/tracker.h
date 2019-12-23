#ifndef TRACKER_H_INCLUDED
#define TRACKER_H_INCLUDED

#include "response.h"
#include <unordered_set>

struct Tracker
{
    void reset();
    int numValid();
    int oneValid();
    const std::unordered_set<int>& allValid();
    void update(int guess, const Response& response);

protected:
    std::unordered_set<int> valid;
};

#endif // TRACKER_H_INCLUDED
