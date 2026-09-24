#pragma once


#include <random>

#include <QPair>

class StdRandom
{
public: // types
    typedef QPair<int, int> Range;

public: // ctors
    StdRandom();
    StdRandom(const Range aRange);
    StdRandom(const int aMax, const int aMin=0);

public: // const
    bool isNull() const;
    bool isStdNull() const;

public: // non-const
    void clear();
    void set(const Range aRange);
    int take();

private:
    std::random_device mDevice;
    std::mt19937 mGenerator;
    std::uniform_int_distribution<int> mDistribution;
    Range mRange;
};
