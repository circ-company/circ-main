#include "Action.h"

#include <QCoreApplication>

#include "ActionManager.h"

Action::Action() : mpAction{nullptr} {;}
Action::Action(const AText &key) { set(key); }

void Action::set(const AText &aKey, const QString &aName)
{
    const Uid cBase(Uid::VerGTimeseqNode6);
    const Key cKey(aKey);
    const AText cName = aName.isEmpty() ? cKey.last()() : aName;
    Uid tUid(Uid::VerTextMd5, cKey(), cBase);
    const IdNo cIdNo = tUid.lo() ^ tUid.hi();
//    const Uid cParentUid = ACTMGR->attachParent(tUid);
    id().uid(tUid);
    id().key(cKey);
    id().name(cName);
    id().idno(cIdNo);
//    id().parentuid(cParentUid);
    mpAction = new QAction(cName, qApp);
}

QString Action::toDebugString() const
{
    return id().name(); // TODO
}

QString Action::unampify(const Key &key)
{
    QString result = key.toString();
    result.replace("&", "");
    return result;
}

