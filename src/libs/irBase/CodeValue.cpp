#include "CodeValue.h"

CodeValue::CodeValue(const QVariant &var, const CText &argName,
                     const QVariant &def, const AText &defName)
    : mValue(var), mName(argName), mMetaType(value().metaType())
    , mDefValue(def), mDefName(defName), mDefMetaType(defValue().metaType()) {;}

CodeValue::CodeValue(const QVariant &var, const char *argPch,
                     const QVariant &def, const char *defPch)
    : mValue(var), mName(argPch), mMetaType(value().metaType())
    , mDefValue(def), mDefName(defPch), mDefMetaType(defValue().metaType()) {;}

QString CodeValue::toDebugString() const
{
    return QString("%1=<%4>:%2(%3)").arg(name()())
        .arg(metaName()()).arg(metaType().id()).arg(string());
}
