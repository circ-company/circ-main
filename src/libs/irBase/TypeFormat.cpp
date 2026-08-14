#include "TypeFormat.h"

#include "BaseTypeFormat.h"
#include "CppTypeFormat.h"
#include "QCoreTypeFormat.h"
#include "QGuiTypeFormat.h"

QMap<int, TypeFormat::FormatFunctionPtr> TypeFormat::smTypeIdFuncPtrMap;

TypeFormat::TypeFormat(const QVariant aVar)
{
    const QMetaType cQMT = aVar.metaType();
    if (smTypeIdFuncPtrMap.isEmpty())
        populate();
    if (smTypeIdFuncPtrMap.contains(cQMT.id()))
    {
        FormatFunctionPtr  pFF = smTypeIdFuncPtrMap.value(cQMT.id());
        set((*pFF)(aVar));
    }
    else
    {
        set(QString("[Unhandled: %1(%2):`%3`]").arg(cQMT.name())
                .arg(cQMT.id()).arg(aVar.toString()));
    }
}

void TypeFormat::registerFunction(const int aTypeId, FormatFunctionPtr pFFn)
{
    smTypeIdFuncPtrMap.insert(aTypeId, pFFn);
}

void TypeFormat::registerFunction(const IntList aTypeIds, FormatFunctionPtr pFFn)
{
    foreach (const int cTypeId, aTypeIds)
        registerFunction(cTypeId, pFFn);
}

void TypeFormat::populate()
{
    BaseTypeFormat::registerBase();
    CppTypeFormat::registerCpp();
    QCoreTypeFormat::registerQCore();
    QGuiTypeFormat::registerQGui();
}

