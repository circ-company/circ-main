#include "CodeValue.h"


//CodeValue::CodeValue(const Type typ, const QVariant &var) : mType(typ), mValue(var) {;}

CodeValue::CodeValue(const Type typ, const QVariant &var, const CText &argName)
    : mType(typ), mValue(var), mName(argName), mMetaType(value().metaType())
{
}

CodeValue::CodeValue(const Type typ, const QVariant &var, const char *argPch)
    : mType(typ), mValue(var), mName(CText(argPch)), mMetaType(value().metaType())
{
}

QString CodeValue::toDebugString() const
{
    return QString("%1 %2(%3)").arg(mName()).arg(mMetaType.name()).arg(mValue.toString());
}
