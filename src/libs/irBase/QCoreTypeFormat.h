#pragma once

#include "TypeFormat.h"

class QCoreTypeFormat : public TypeFormat
{
public:
    static void registerQCore();
    static AText formatQChar(const QVariant &aVar);
    static AText formatString(const QVariant &aVar);
    static AText formatHexData(const QVariant &aVar);
    static AText formatQSize(const QVariant &aVar);
    static AText formatQRect(const QVariant &aVar);
    static AText formatQFileInfo(const QVariant &aVar);

};
