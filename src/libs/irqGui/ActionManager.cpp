#include "ActionManager.h"

#include "QQAction.h"

ActionManager::ActionManager(QCoreApplication *parent)
    : QObject{parent}
    , mParentId(Uid::VerGTimeseqNode6, Key("ActionManager/Parent"))
{
    setObjectName("ActionManager:" + parent->applicationName());
}

QQAction *ActionManager::add(const Key &key)
{
    QQAction * pAct = new QQAction(key);
    mKeyActionMap.insert(key, pAct);
    return pAct;
}


Uid ActionManager::attachParent(const Uid childUid)
{
    mParentId.ptrchilduids()->append(childUid);
    return mParentId.uid();
}
