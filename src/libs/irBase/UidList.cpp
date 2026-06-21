#include "UidList.h"

UidList::UidList() { clear(); }
UidList::UidList(const QList<Uid> &cListUids) { set(cListUids); }

void UidList::set(const QList<Uid> &cListUids)
{
    clear();
    foreach (const Uid cUid, cListUids) append(cUid);
}
