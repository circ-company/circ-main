#pragma once

#include "CText.h"
#include "Types.h"

class Utility
{
public: // ctors
    Utility();

public: // static
    template<typename T>
    static bool inRange(const T &loT, const T &valT, const T &hiT);

    template<typename ENUM>
    static CText enumName(const ENUM eval);

    template<typename ENUM>
    static ENUM fromName(const ENUM loEnum, const CText &nam, const ENUM hiEnum);
};

template<typename ENUM>
inline ENUM Utility::fromName(const ENUM loEnum, const CText &nam, const ENUM hiEnum)
{
    ENUM result = ENUM();
    for (Index ix = loEnum; ix < hiEnum; ++ix)
    {
        QVariant tVar;
        tVar.setValue((ENUM(ix)));
        const QString cStr = tVar.toString();
        const CText cCtx(cStr);
        if (cCtx.like(nam, CText::Lower))
        {
            result = ENUM(ix);
            break;
        }
    }
    return result;
}

template<typename ENUM>
inline CText Utility::enumName(const ENUM eval)
{
    return QVariant(eval).toByteArray();
}

template<typename T>
inline bool Utility::inRange(const T &loT, const T &valT, const T &hiT)
{
    Q_ASSERT(loT < hiT);
    return loT <= valT && valT < hiT;
}

