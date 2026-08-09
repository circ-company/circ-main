#pragma once

#include <QVariant>

#include <QList>

#include "AText.h"
#include "ATextList.h"
#include "CText.h"
#include "Key.h"
#include "KeyList.h"
#include "UText.h"

template <typename T>
class KeyMapT : public QMap<Key, T>
{
public: // ctors
    KeyMapT() {;}
    KeyMapT(const CText &aName) : mName(aName) {;}

public: // const
    CText name() { return mName; }
    KeyList allkeys() const;
    KeyList groupKeys(const Key &aGroupKey) const;
    KeyMapT<T> extract(const Key &aGroupKey) const;
    KeyList levelKeys(const Count &aLevels) const;
    Key currentGroup() const { return mCurrentGroup; }
    bool containsGroup(const Key &key) const;

public: // non-const
    void enterGroup(const KeySeg &seg) { mCurrentGroup.append(seg); }
    void leaveGroup() { mCurrentGroup.removeLast(); }
    void clearGroup() { mCurrentGroup.clear(); }
    bool set(const Key &key, const T &t, const bool override=false);
    void import(const ATextList &atxl, const char sep='=', const bool override=false);

public: // pointers

public: // debug
    QStringList toDebugStrings();


private:
    CText mName;
    Key mCurrentGroup;
};

typedef KeyMapT<QVariant> KeyMap;
typedef KeyMapT<IdNo> KeyIdNoMap;
typedef KeyMapT<UText> KeyUTextMap;



template<typename T>
inline KeyList KeyMapT<T>::allkeys() const
{
    return QMap<Key, T>::keys();
}

template<typename T>
inline KeyList KeyMapT<T>::groupKeys(const Key &aGroupKey) const
{
    KeyList result;
    const KeyList cAllKeys = KeyMapT<T>::keys();
    foreach (const Key cKey, cAllKeys)
        if (cKey.startsWith(aGroupKey))
            result << cKey;
    return result;
}

template<typename T>
inline KeyMapT<T> KeyMapT<T>::extract(const Key &aGroupKey) const
{
    KeyMapT<T> result;
    const KeyList cGroupKeys = KeyMapT<T>::groupKeys(aGroupKey);
    foreach (const Key cKey, cGroupKeys)
    {
        const T cValue = KeyMapT<T>::value(cKey);
        result.insert(cKey, cValue);
    }
    return result;
}

template<typename T>
inline KeyList KeyMapT<T>::levelKeys(const Count &aLevels) const
{
    KeyList result;
    const KeyList cAllKeys = KeyMapT<T>::keys();
    foreach (const Key cKey, cAllKeys)
    {
        const Key cStart = cKey.mid(0, aLevels);
        if ( ! result.contains(cStart))
            result << cStart;
    }
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

template<typename T>
inline QStringList KeyMapT<T>::toDebugStrings()
{
    QStringList result;
    const KeyList cKeyList = allkeys();
    foreach (const Key cKey, cKeyList)
        result << QString("%1 = %2").arg(cKey, -32)
                      .arg(KeyMapT<T>::value(cKey)());
    return result;
}
