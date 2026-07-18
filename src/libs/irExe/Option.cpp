#include "Option.h"


Option::Option(Options *mpOpts, const KeySeg &aName)
    : mpOptions(mpOpts)
    , mCLOption(aName())
    , mName(aName)
{

}

Option::Option(Options *mpOpts, const KeySeg &aName, const QChar &aChar)
    : mpOptions(mpOpts)
    , mCLOption(QStringList() << aName() << QString(aChar))
    , mName(aName)
    , mChar(aChar)
{

}

Option::Option(Options *mpOpts, const KeySeg &aName, const KeySegList &aExtras)
    : mpOptions(mpOpts)
    , mCLOption(QStringList() << aName() << aExtras.toStringList())
    , mName(aName)
    , mExtraNames(aExtras)
{

}

Option::Option(Options *mpOpts, const KeySeg &aName, const KeySegList &aExtras, const QChar &aChar)
    : mpOptions(mpOpts)
    , mCLOption(QStringList() << aName() << aExtras.toStringList() << QString(aChar))
    , mName(aName)
    , mExtraNames(aExtras)
    , mChar(aChar)
{

}

void Option::valueDefault(const QString &aDefVal)
{
    mValueDefaults.clear();
    mValueDefaults << aDefVal;
}

void Option::generate()
{
    mCLOption.setDescription(mDescription);
    mCLOption.setValueName(mValueName);
    mCLOption.setDefaultValues(mValueDefaults);

}
