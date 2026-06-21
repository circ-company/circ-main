#pragma once

#include "Uid.h"

class UidList : public Uid::List
{
public:
    UidList();
    UidList(const QList<Uid> &cListUids);

public:
    void set(const QList<Uid> &cListUids);
};
