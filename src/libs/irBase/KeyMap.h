#pragma once

#include <QVariant>

#include "AText.h"
#include "ATextList.h"
#include "Key.h"
#include "KeyList.h"
#include "UText.h"

template <typename T>
class KeyMapT : public QMap<Key, T>
{
public: // ctors
    KeyMapT() {;}

public: // const
    KeyList allkeys() const { return QMap<Key, T>::keys(); }
    KeyList keys(const Key &starts) const;
    Key currentGroup() const { return mCurrentGroup; }
    bool containsGroup(const Key &key) const;

public: // non-const
    bool enterGroup(const Key &key);
    bool leaveGroup(const Key &key);
    void clearGroup() { mCurrentGroup.clear(); }
    bool set(const Key &key, const T &t, const bool override=false);
    void import(const ATextList &atxl, const char sep='=', const bool override=false);

public: // pointers

private:
    Key mCurrentGroup;
};

typedef KeyMapT<QVariant> KeyMap;
typedef KeyMapT<IdNo> KeyIdNoMap;
typedef KeyMapT<AText> KeyTextMap;
typedef KeyMapT<UText> KeyUTextMap;



template<typename T>
inline KeyList KeyMapT<T>::keys(const Key &starts) const
{
    KeyList result;
    const KeyList cAllKeys = KeyMapT<T>::keys();
    foreach (const Key cKey, cAllKeys)
        if (cKey.startsWith(starts))
            result << cKey;
    return result;
}



template<typename T>
inline bool KeyMapT<T>::containsGroup(const Key &key) const
{
    const Key cGroupKey = currentGroup() + key;
    const KeyList cGroupKeys = allkeys();
    foreach (const Key cKey, cGroupKeys)
        if (cKey.startsWith(key))
            return true;
    return false;
}

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
