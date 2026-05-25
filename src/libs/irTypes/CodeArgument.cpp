#include "CodeArgument.h"


CodeArgument::CodeArgument(const QVariant &var) : mValue(var) {;}

CodeArgument::CodeArgument(const QVariant &var, const CText &argName, const CText &typeName)
    : mValue(var), mArgumentName(argName), mTypeMetaName(typeName)
{
    mMetaType = QMetaType::fromName(mTypeMetaName);
}

QString CodeArgument::toDebugString() const
{
    return QString("%1 %2(%3)").arg(mArgumentName()).arg(mMetaType.name()).arg(mValue.toString());
}
