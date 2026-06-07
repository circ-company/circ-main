#pragma once
/*! @file EnumHelper.h Declarations for enumeration support class
*
*/

#include <QMetaEnum>
#include <QList>

#include "CText.h"
#include "Utility.h"

namespace EnumHelper
{

template<typename ENUM>
ENUM value(const CText ekey, bool * pOk)
{
    ENUM result = static_cast<ENUM>(QMetaEnum::fromType<ENUM>()
                                        .keyToValue(ekey, pOk));
    return result;
}

template<typename ENUM>
ENUM value(const CText ekey)
{
    bool ok;
    ENUM result = static_cast<ENUM>(QMetaEnum::fromType<ENUM>()
                                        .keyToValue(ekey, &ok));
    Q_ASSERT(ok);
    return result;
}

template<typename ENUM>
CText name(const ENUM eval)
{
    const short cInt = static_cast<short>(eval);
    return CText(QMetaEnum::fromType<ENUM>().valueToKey(cInt));
}

template<typename ENUM>
bool inRange(const ENUM evlo, const ENUM eval, const ENUM evhi)
{
    return Utility::inRange(evlo, eval, evhi);
}

template<typename ENUM>
QList<WORD> values()
{
    QList<WORD> result;
    QMetaEnum mQME = QMetaEnum::fromType<ENUM>();
    const Count cCount = mQME.keyCount();
    for (Index ix = 0; ix < Index(cCount); ++ix)
        result.append(mQME.value(ix));
    return result;
}

} // EnumHelper
