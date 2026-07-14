#pragma once

#include <QVariant>

#include "AText.h"
#include "ATextList.h"
#include "KeySeg.h"
#include "KeySegList.h"


template <typename T>
class KeySegMapT : public QMap<KeySeg, T>
{
public: // ctors
    KeySegMapT() {;}

public: // const
    KeySegList allkeys() const { return QMap<KeySeg, T>::keys(); }

public: // non-const
    bool set(const KeySeg &key, const T &t, const bool override=false);
    void import(const ATextList &atxl, const char sep='=', const bool override=false);

public: // pointers

private:
};

typedef KeySegMapT<QVariant> KeySegMap;
typedef KeySegMapT<IdNo> KeySegIdNoMap;
typedef KeySegMapT<AText> KeySegTextMap;


template<typename T>
inline bool KeySegMapT<T>::set(const KeySeg &key, const T &t, const bool override)
{
    const bool cExists = KeySegMapT<T>::contains(key);
    if ( ! cExists)
    {
        KeySegMapT<T>::insert(key, t);
        return true;
    }
    else if (override)
    {
        KeySegMapT<T>::remove(key);
        KeySegMapT<T>::insert(key, t);
        return true;
    }
    else
    {
        return false;
    }

}

