#pragma once

#include <QVariant>

#include "AText.h"
#include "ATextList.h"
#include "Key.h"

template <typename T>
class KeyMapT : public QMap<Key, T>
{
public:
    KeyMapT() {;}

public:
    bool set(const Key &key, const T &t, const bool override=false);
    void import(const ATextList &atxl, const char sep='=', const bool override=false);

};

typedef KeyMapT<QVariant> KeyMap;
typedef KeyMapT<IdNo> KeyIdNoMap;
typedef KeyMapT<AText> KeyTextMap;

template<typename T>
inline bool KeyMapT<T>::set(const Key &key, const T &t, const bool override)
{
    const bool cExists = KeyMapT<T>::contains(key);
    if ( ! cExists)
    {
        KeyMapT<T>::insert(key, t);
        return true;
    }
    else if (override)
    {
        KeyMapT<T>::remove(key);
        KeyMapT<T>::insert(key, t);
        return true;
    }
    else
    {
        return false;
    }

}
