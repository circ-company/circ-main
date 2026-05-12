#include "StatusCodeArgument.h"


StatusCodeArgument::StatusCodeArgument(const QVariant &var) : mValue(var) {;}

StatusCodeArgument::StatusCodeArgument(const QVariant &var, const CText &argName, const CText &typeName)
    : mValue(var), mArgumentName(argName), mTypeMetaName(typeName)
{
    mMetaType = QMetaType::fromName(mTypeMetaName);
}
