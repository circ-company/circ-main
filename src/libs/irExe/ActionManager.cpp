#include "ActionManager.h"

#include "Action.h"

ActionManager::ActionManager(QCoreApplication *parent)
    : QObject{parent}
    , mParentId(Uid::VerGTimeseqNode6, Key("ActionManager/Parent"))
{
    setObjectName("ActionManager:" + parent->applicationName());
}

Action *ActionManager::add(const Key &key)
{
    Action * pAct = new Action(key());
    mKeyActionMap.insert(key, pAct);
    return pAct;
}


Uid ActionManager::attachParent(const Uid childUid)
{
    mParentId.ptrchilduids()->append(childUid);
    return mParentId.uid();
}
