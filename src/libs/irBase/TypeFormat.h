#pragma once

#include "AText.h"

#include <QList>
#include <QMetaType>
#include <QVariant>

#include "Types.h"

class TypeFormat : public AText
{
public:
    typedef AText (*FormatFunctionPtr)(const QVariant &aVar);
    typedef QList<QMetaType> MetaTypeList;

public:
    TypeFormat(const QVariant aVar);

protected:
    static void registerFunction(const int aTypeId, FormatFunctionPtr pFFn);
    static void registerFunction(const IntList aQMTs, FormatFunctionPtr pFFn);

private:
    static void populate();

protected:
    static QMap<int, FormatFunctionPtr> smTypeIdFuncPtrMap;
};



