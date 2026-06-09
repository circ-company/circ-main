#pragma once
/*! @file EnumHelper.h Declarations for enumeration support class
*
*/

#include <QMetaEnum>
#include <QList>

#include "CText.h"
#include "Types.h"
#include "Utility.h"

namespace EnumHelper
{

template<typename ENUM>
ENUM evalue(const int val, bool * pOk)
{
    ENUM result = ENUM();
    *pOk = false;
    const QMetaEnum cQME = QMetaEnum::fromType<ENUM>();
    const Count cCount = cQME.keyCount();
    for (Index ix = 0; ix < Index(cCount); ++ix)
        if (val == cQME.value(ix))
        {
            result = ENUM(val);
            *pOk = true;
            break;
        }
    return result;
}

template<typename ENUM>
ENUM evalue(const CText &ekey, bool * pOk)
{
    ENUM result = static_cast<ENUM>(QMetaEnum::fromType<ENUM>()
                                        .keyToValue(ekey, pOk));
    return result;
}

template<typename ENUM>
ENUM evalue(const int val)
{
    bool ok;
    ENUM result = evalue<ENUM>(val, &ok);
    Q_ASSERT(ok);
    return result;
}

template<typename ENUM>
ENUM evalue(const CText &ekey)
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
    const int cInt = static_cast<short>(eval);
    return CText(QMetaEnum::fromType<ENUM>().valueToKey(cInt));
}

template<typename ENUM>
bool inRange(const ENUM evlo, const ENUM eval, const ENUM evhi)
{
    return Utility::inRange(evlo, eval, evhi);
}

template<typename ENUM>
IntList values()
{
    IntList result;
    const QMetaEnum cQME = QMetaEnum::fromType<ENUM>();
    const Count cCount = cQME.keyCount();
    for (Index ix = 0; ix < Index(cCount); ++ix)
        result.append(cQME.value(ix));
    return result;
}

} // EnumHelper
