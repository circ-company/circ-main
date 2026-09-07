#pragma once

template <typename T> class Contained
{
public:
    Contained(const T &aLowerT, const T &aValueT, const T &aUpperT);

    operator bool () { return mIs;}
    bool operator () () { return mIs; }

private:
    bool mIs=false;
};

template<typename T>
inline Contained<T>::Contained(const T &aLowerT, const T &aValueT, const T &aUpperT)
{
    mIs = (aLowerT <= aValueT) && (aValueT <= aUpperT);
}

