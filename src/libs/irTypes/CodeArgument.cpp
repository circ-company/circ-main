#include "CodeArgument.h"


CodeArgument::CodeArgument(const QVariant &var) : mValue(var) {;}

CodeArgument::CodeArgument(const QVariant &var, const CText &argName, const CText &typeName)
    : mValue(var), mArgumentName(argName), mTypeMetaName(typeName)
{
    mMetaType = QMetaType::fromName(mTypeMetaName);
}
