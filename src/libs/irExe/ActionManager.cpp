#include "ActionManager.h"

#include <Log.h>

#include "Action.h"

ActionManager::ActionManager(QCoreApplication *parent)
    : QObject{parent}
    , mParentId(Uid::VerGTimeseqNode6, Key("ActionManager/Parent"))
{
    setObjectName("ActionManager:" + parent->applicationName());
}

Action *ActionManager::add(const Key &aKey)
{
    FNENTER();
    FNARG(aKey(), "QString");
    Action * result = new Action(aKey());
    mKeyActionMap.insert(aKey, result);
    FNRTNVALUE(result->id().name(), "QString");
    return result;
}

Action *ActionManager::action(const Key &aKey)
{
    Action * result = nullptr;
    if (mKeyActionMap.contains(aKey))
        result = mKeyActionMap.value(aKey);
    MASSERT(result);
    return result;
}


Action *ActionManager::action(const Key &aKey) const
{
    FNENTER();
    FNARG(aKey(), "QString");
    Action * result = nullptr;
    if (contains(aKey))
        result = mKeyActionMap.value(aKey);
    WASSERT(result);
    FNRTNVALUE(result ? result->id().name() : "<NULL>", "QString");
    return result;
}

Uid ActionManager::attachParent(const Uid childUid)
{
    mParentId.ptrchilduids()->append(childUid);
    return mParentId.uid();
}

QStringList ActionManager::toDebugStrings() const
{
    QStringList results;
    results << QString("{--%1: %2 entries%3")
                    .arg(objectName())
                    .arg(mKeyActionMap.count())
                    .arg(mKeyActionMap.isEmpty() ? "]" : "");
    Index tIndex = 0;
    foreach (const Key cKey, mKeyActionMap.allkeys())
    {
        Action * pAction = mKeyActionMap.value(cKey);
        if (pAction)
            results << QString("   %1. %2 = %3")
                           .arg(++tIndex, 2)
                           .arg(cKey, 20)
                           .arg(pAction->toDebugString());
        else
            results << QString("   %1. %2 <Missing>")
                           .arg(++tIndex, 2)
                           .arg(cKey, 20);
    }
    // TODO
    return results;
}
