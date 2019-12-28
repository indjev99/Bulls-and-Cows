#ifndef SYMMETRY_TRACKER_H_INCLUDED
#define SYMMETRY_TRACKER_H_INCLUDED

#include <vector>
#include <unordered_set>

struct SymmetryTracker
{
    void reset();
    void update(int guess);
    SymmetryTracker afterUpdate(int guess) const;
    bool isUnique(int number) const;
    std::vector<int> reduce(const std::unordered_set<int>& numbers) const;
    std::vector<int> reduce(const std::vector<int>& numbers) const;

private:
    int turn;
    std::unordered_set<int> unasked;
    int zeroPos;
    std::vector<int> firstDigs;
    std::vector<int> firstPos;

    bool isUniqueTurn0(const std::vector<int> digits) const;
    bool isUniqueTurn1(const std::vector<int> digits) const;
};

#endif // SYMMETRY_TRACKER_H_INCLUDED
