#pragma once

#include <QList>


template <typename T>
class ListT : public QList<T>
{
public: // ctors
    ListT() {;}
    ListT(const QList<T> &other) { *this = other; }

public: // const
    bool isValidIndex(const qsizetype ix) const;
    ListT<T> constFirst(qsizetype k) const;
    T constFirst(const qsizetype k, const T tJoin) const;
    T constFirst(const qsizetype k, const char cJoin) const;
    T constLast() const;
    T join(const char cJoin) const;
    ListT<T> constLast(qsizetype k) const;
    T constLast(const qsizetype k, const T tJoin) const;

public: // non-const
    void set(const qsizetype ix, const T &t);
    void operator <<(const T &t);
};

template<typename T>
inline bool ListT<T>::isValidIndex(const qsizetype ix) const
{
    return ix >= 0 && ix < ListT<T>::count();
}

template<typename T>
inline ListT<T> ListT<T>::constFirst(qsizetype k) const
{
    ListT<T> result;
    if (k < 0) k = ListT<T>::count() + k;
    qsizetype ix = 0;
    while (ix < k)
        result << ListT<T>::at(ix);
    return result;
}

template<typename T>
inline T ListT<T>::constFirst(const qsizetype k, const T tJoin) const
{
    ListT<T> tList = constFirst(k);
    return tList.join(tJoin);
}

template<typename T>
inline T ListT<T>::constFirst(const qsizetype k, const char cJoin) const
{
    ListT<T> tList = constFirst(k);
    return tList.join(cJoin);
}

template<typename T>
inline T ListT<T>::constLast() const
{
    return ListT<T>::last();
}

template<typename T>
inline T ListT<T>::join(const char cJoin) const
{
    T result;
    ListT<T> tList = *this;
    if ( ! tList.isEmpty())
    {
        result = tList.takeFirst();
        while ( ! tList.isEmpty())
            result += T(cJoin) + tList.takeFirst();
    }
    return result;
}

template<typename T>
inline ListT<T> ListT<T>::constLast(qsizetype k) const
{
    ListT<T> result;
    if (k < 0) k = ListT<T>::count() + k;
    qsizetype ix = ListT<T>::count();
    while (result.count() < k)
        result << ListT<T>::at(--ix);
    return result;
}

template<typename T>
inline T ListT<T>::constLast(const qsizetype k, const T tJoin) const
{
    ListT<T> tList = constLast(k);
    return tList.join(tJoin);
}

template<typename T>
inline void ListT<T>::set(const qsizetype ix, const T &t)
{
    qsizetype ix2 = ListT<T>::count();
    while (ix2++ <= ix) ListT<T>::append(T());
    ListT<T>::replace(ix, t);
}

template<typename T>
inline void ListT<T>::operator <<(const T &t)
{
    ListT<T>::append(t);
}
