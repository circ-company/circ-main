#pragma once

#include "TypeFormat.h"

class BaseTypeFormat : public TypeFormat
{
public:
    static void registerBase();
    static AText formatFileInfo(const QVariant &aVar);
    static AText formatUrl(const QVariant &aVar);
};
