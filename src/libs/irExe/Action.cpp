#include "Action.h"

#include "ActionManager.h"

Action::Action() : mpAction{nullptr} {;}
Action::Action(const AText &key) : mpAction(new QAction(ACTMGR)) { set(key); }

void Action::set(const AText &key)
{
    const Uid cBase(Uid::VerUTimeseqRandom);
    const Key cKey(key);
    const AText cName = (id().name().isEmpty()) ? ampify(key) : id().name();
    Uid tUid(Uid::VerTextMd5, cKey(), cBase);
    const IdNo cIdNo = tUid.lo() ^ tUid.hi();
    const Uid cParentUid = ACTMGR->attachParent(tUid);

    id().uid(tUid);
    id().key(cKey);
    id().name(cName);
    id().idno(cIdNo);
    id().parentuid(cParentUid);

}

QString Action::ampify(const Key &key)
{
    QString result = key.toString();
    result.replace("&", "&&");
    result.replace("/", "/&");
    return result;
}

