#include "CodeValue.h"


//CodeValue::CodeValue(const Type typ)
  //  : mType(typ), mValue(QVariant()), mName(CText()), mMetaType(QMetaType()) {;}
CodeValue::CodeValue(const Type typ, const QVariant &var, const CText &argName)
    : mType(typ), mValue(var), mName(argName), mMetaType(value().metaType()) {;}
CodeValue::CodeValue(const Type typ, const QVariant &var, const char *argPch)
    : mType(typ), mValue(var), mName(CText(argPch)), mMetaType(value().metaType()) {;}


QString CodeValue::toDebugString() const
{
    return QString("%1=%2(%3): <%4>").arg(name()())
        .arg(metaType().name()).arg(metaType().id()).arg(string());
}
