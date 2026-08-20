#pragma once

#include <QMetaType>

#include "TriBool.h"

class IntType : public QMetaType
{
public:
    IntType();
    IntType(const int aId);
    IntType(const QMetaType &aOther);
    TriBool isSigned() const;
};
