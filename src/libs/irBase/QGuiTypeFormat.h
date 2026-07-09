#pragma once

#include "TypeFormat.h"

class QGuiTypeFormat : public TypeFormat
{
public:
    static void registerQGui();
    static AText formatImage(const QVariant &aVar);
};
