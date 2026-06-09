#include "CodeValue.h"


//CodeValue::CodeValue(const Type typ)
  //  : mType(typ), mValue(QVariant()), mName(CText()), mMetaType(QMetaType()) {;}
CodeValue::CodeValue(const QVariant &var, const CText &argName)
    : mValue(var), mName(argName), mMetaType(value().metaType()) {;}
CodeValue::CodeValue(const QVariant &var, const char *argPch)
    : mValue(var), mName(CText(argPch)), mMetaType(value().metaType()) {;}


QString CodeValue::toDebugString() const
{
    return QString("%1=<%4>:%2(%3)").arg(name()())
        .arg(metaName()()).arg(metaType().id()).arg(string());
}
