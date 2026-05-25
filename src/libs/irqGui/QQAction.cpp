#include "QQAction.h"

QQAction::QQAction() : mpAction{nullptr} {;}
QQAction::QQAction(const Key &key) : mpAction(new QAction(ACTMGR)) { set(key); }

void QQAction::set(const Key &key)
{
    const Uid cBase(Uid::VerUTimeseqRandom);
    const Key cKey(key);
    const AText cName = (id().name().isEmpty()) ? ampify(cKey) : id().name();
    Uid tUid(Uid::VerTextMd5, key.toString(), cBase);
    const IdNo cIdNo = tUid.lo() ^ tUid.hi();
    const Uid cParentUid = ACTMGR->attachParent(tUid);

    id().uid(tUid);
    id().key(cKey);
    id().name(cName);
    id().idno(cIdNo);
    id().parentuid(cParentUid);

}

QString QQAction::ampify(const Key &key)
{
    QString result = key.toString();
    result.replace("&", "&&");
    result.replace("/", "/&");
    return result;
}

