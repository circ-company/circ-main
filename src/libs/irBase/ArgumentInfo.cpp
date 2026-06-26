#include "ArgumentInfo.h"


ArgumentInfo::ArgumentInfo(const CText aName)
    : mName(aName) {;}

ArgumentInfo::ArgumentInfo(const CText aName, const QMetaType aMetaType)
    : mName(aName)
    , mMetaType(aMetaType) {;}

ArgumentInfo::ArgumentInfo(const char *aPCH, const QVariant aValue)
    : mName(CText(aPCH))
    , mMetaType(aValue.metaType())
    , mValue(aValue) {;}

ArgumentInfo::ArgumentInfo(const CText aName, const QVariant aValue)
    : mName(aName)
    , mMetaType(aValue.metaType())
    , mValue(aValue) {;}

ArgumentInfo::ArgumentInfo(const CText aName,
                           const AText &aValueText, const QVariant &aValue)
    : mName(aName)
    , mMetaType(aValue.metaType())
    , mValueText(aValueText)
    , mValue(aValue) {;}

ArgumentInfo::ArgumentInfo(const CText aName,
                           const AText &aValueText, const QVariant &aValue,
                           const AText &aDefaultText, const QVariant aDefault)
    : mName(aName)
    , mMetaType(aValue.metaType())
    , mValueText(aValueText)
    , mValue(aValue)
    , mDefaultText(aDefaultText)
    , mDefault(aDefault) {;}

void ArgumentInfo::clear()
{
    mName.clear();
    mMetaType = QMetaType();
    mValueText.clear();
    mValue.clear();
    mDefault.clear();
    mDescription.clear();
}

QString ArgumentInfo::toDebugString() const
{
    return QString("{%1: %2<%3> def<%4> type<%5>(%6) '%7'}")
        .arg(mName(),
             mValueText(),
             mValue.toString(),
             mDefault.toString(),
             mMetaType.name())
        .arg(mMetaType.id())
        .arg(mDescription);
}


