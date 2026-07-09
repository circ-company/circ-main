#pragma once

#include <QMetaType>

#include "TriBool.h"

class MetaType : public QMetaType
{
public:
    MetaType();
    MetaType(const int aId);
    MetaType(const QMetaType &aOther);
    TriBool isSigned() const;
};
