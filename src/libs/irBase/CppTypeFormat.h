#pragma once

#include "TypeFormat.h"

class CppTypeFormat : public TypeFormat
{
public:
    static void registerCpp();
    static AText formatVoid(const QVariant &aVar);
    static AText formatBool(const QVariant &aVar);
    static AText formatSigned(const QVariant &aVar);
    static AText formatUnsigned(const QVariant &aVar);
    static AText formatChar(const QVariant &aVar);
    static AText formatUChar(const QVariant &aVar);
    static AText formatString(const QVariant &aVar);
};
