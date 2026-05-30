#pragma once

#include <KeyMap.h>
#include <List.h>

#include "Signum.h"

template <typename T>
class CircularArrayT
{
public: // ctors
    CircularArrayT() {;}
    CircularArrayT(const CircularArrayT &other) { *this = other; }

public: // const
    bool isEmpty() const { return mHeadIndex == mTailIndex; }
    bool isOverflow() const { return count() > mCapacity; }
    unsigned count() const { return mHeadIndex - mTailIndex; }
    qsizetype capacity() const { return mCapacity; }
    bool isValidIndex(const qsizetype ix) const;
    T at(const qsizetype ix) const; // safe, no assert
    T peekHead() const;
    T peekTail() const;
    ListT<T> peekHead(const qsizetype k) const;
    T peekHead(const qsizetype k, const T tJoin) const;
    T peekHead(const qsizetype k, const char cJoin) const;
    ListT<T> peekAll() const;
    T joinAll(const char cJoin) const;
    ListT<T> constTail(const qsizetype k) const;
    T constTail(const qsizetype k, const T tJoin) const;

public: // non-const
    void initialize(const KeyMap config);
    void initialize(const qsizetype capacity);
    void clear();
    T dequeue() const;
    ListT<T> dequeue(qsizetype k) const;
    ListT<T> dequeueAll() const;

private:
    qsizetype mHeadIndex=0; // Past where we last put something mod capacity
    qsizetype mTailIndex=0; // Where we will take the next mod capacity
    qsizetype mIndexMask=0;
    qsizetype mCapacity=0;
    KeyMap mConfig;
    T mArray[];
};

template<typename T> inline bool CircularArrayT<T>::isValidIndex(const qsizetype ix) const { return ix >= mTailIndex && ix < mHeadIndex; }
template<typename T> inline T CircularArrayT<T>::at(const qsizetype ix) const { return (isValidIndex(ix)) ? mArray[ix & mIndexMask] : T(); }
template<typename T> inline T CircularArrayT<T>::peekHead() const { return isOverflow() ? T() : mArray[mTailIndex & mIndexMask]; }
template<typename T> inline T CircularArrayT<T>::peekTail() const { return Signum(mHeadIndex).positive() ? T() : mArray[mHeadIndex-1 & mIndexMask]; }

