#pragma once

#include "StatusCode.h"

#include <QMetaType>
#include <QVariantList>

#include <List.h>
#include <Key.h>
#include <Types.h>
#include <Uid.h>

class StatusItem : public StatusCode
{
public: // types
    typedef ListT<StatusItem> List;

public: // ctors
    StatusItem(const Key &aKey, const CodeContext &aContext);

public: // const

public: // non-const
    void add(const QVariant &aVar);

public: // pointers

private:
    Uid mInstanceUid;
    CodeContext mContext;
    QVariantList mValues;

public: // QMetaType
    StatusItem() = default;
    ~StatusItem() = default;
    StatusItem(const StatusItem &) = default;
    StatusItem &operator=(const StatusItem &) = default;
    StatusItem & it() { return *this; }
    const StatusItem & it() const { return *this; }
};

Q_DECLARE_METATYPE(StatusItem);
