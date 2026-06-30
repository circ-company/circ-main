#pragma once

#include <QMetaType>

#include <TriBool.h>

class QQMetaType : public QMetaType
{
public:
    QQMetaType();
    QQMetaType(const int aId);
    TriBool isSigned() const;

};
