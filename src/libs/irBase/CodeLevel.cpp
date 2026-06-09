#include "CodeLevel.h"

#include <QtDebug>
#include <QCoreApplication>

#include "EnumHelper.h"
#include "Utility.h"

CodeLevel::CodeLevel(const BYTE val)   : QObject{qApp} { set(val); }
CodeLevel::CodeLevel(const CText &nam) : QObject{qApp} { set(nam); }

bool CodeLevel::inRange(const CodeLevel &lo, const CodeLevel &hi) const
{
    return Utility::inRange(lo, *it(), hi);
}

CText CodeLevel::name() const
{
    return EnumHelper::name<Enum>(evalue());
}

bool CodeLevel::set(const int val)
{
    bool result;
    const Enum cEnum = EnumHelper::evalue<Enum>(val, &result);
    if (result) mEnum = cEnum;
    return result;
}

bool CodeLevel::set(const CText &key)
{
    bool result = false;
    Enum tEnum = EnumHelper::evalue<Enum>(key, &result);
    if (result) mEnum = tEnum;
    return result;
}

bool operator == (const CodeLevel &lhs, const CodeLevel &rhs)
{
    return lhs.equal(rhs);
}

bool operator < (const CodeLevel &lhs, const CodeLevel &rhs)
{
    return lhs.less(rhs);
}

bool operator <= (const CodeLevel &lhs, const CodeLevel &rhs)
{
    return lhs.less(rhs) || lhs.equal(rhs);
}

