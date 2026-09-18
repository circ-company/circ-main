#pragma once
/*! @file Loop.h Declaration/Definition of LoopT<T> template
 */

#include <QList>

#include <Types.h>

template <typename T> class LoopT
{
public: // ctors
    LoopT() {;}
    LoopT(const LoopT &other) { *this = other; }

public: // const
    bool isEmpty() const { return mListOfTs.isEmpty(); }
    Count count() const { return mListOfTs.count(); }
    Count size() const { return count(); }
    Count capacity() const { return mListOfTs.capacity(); }
    bool isValidIndex(const Index ix) const;
    T at(const Index ix) const;
    T peek() const { return at(mHeadIndex); }
    T * p(const Index ix) const { return &at(ix); }

public: // non-const
    void add(const T aT) { mListOfTs.append(aT); }
    void add(const QList<T> aBunchOfTs) { mListOfTs.append(aBunchOfTs); }
    void replace(const Index ix, const T aT);
    void reserve(const Count aCount) { mListOfTs.reserve(aCount); }
    void fill(const Count aCount);
    void increment();
    T take();

protected:
    QList<T> mListOfTs;
    Index mHeadIndex=-1;
};
template<typename T>
inline bool LoopT<T>::isValidIndex(const Index ix) const
{
    return ix >= 0 && ix < size();
}

template<typename T>
inline T LoopT<T>::at(const Index ix) const
{
    return isValidIndex(ix) ? mListOfTs.value(ix) : T();
}

template<typename T>
inline void LoopT<T>::replace(const Index ix, const T aT)
{
    if (isValidIndex(ix))
        mListOfTs.replace(Count(ix), aT);
}

template<typename T>
inline void LoopT<T>::fill(const Count aCount)
{
    if (capacity() < aCount)
        reserve(aCount);
    mListOfTs.fill(T(), aCount);
}

template<typename T>
inline void LoopT<T>::increment()
{
    if ( ! isEmpty())
        mHeadIndex = ++mHeadIndex % size();
    else
        mHeadIndex = -1;
}

template<typename T>
inline T LoopT<T>::take()
{
    T result = peek();
    increment();
    return result;
}


