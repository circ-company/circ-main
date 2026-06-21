#include "StatusCode.h"

#include <Log.h>

StatusCode::StatusCode(const Key &aKey, const StatusLevel aLevel,
                       const AText aMessage, const AText aDesc)
    : Id(aKey)
    , mLevel(aLevel)
    , mFormat(aMessage)
    , mDescription(aDesc)
{;}

StatusCode::StatusCode(const Key &aKey, const StatusLevel aLevel,
                       const AText aFormat,
                       const CodeValue &arg1, const CodeValue &arg2,
                       const CodeValue &arg3, const CodeValue &arg4,
                       const AText aDesc)
    : Id(aKey)
    , mLevel(aLevel)
    , mFormat(aFormat)
    , mDescription(aDesc)
{
    mValues.append(arg1);
    if ( ! arg2.isNull()) mValues.append(arg2);
    if ( ! arg3.isNull()) mValues.append(arg3);
    if ( ! arg4.isNull()) mValues.append(arg4);
}

StatusCode::StatusCode(const Key &aKey, const StatusLevel aLevel,
                       const AText aFormat, const CodeValueList &aValues,
                       const AText aDesc)
    : Id(aKey)
    , mLevel(aLevel)
    , mFormat(aFormat)
    , mDescription(aDesc)
    , mValues(aValues)
{;}

AText StatusCode::formatted() const
{
    AText result;
    FNENTER();
    MUSTDO(); // TODO
    return result;
}

ATextList StatusCode::formattedMulti() const
{
    AText result;
    FNENTER();
    MUSTDO(); // TODO
    return result;
}






