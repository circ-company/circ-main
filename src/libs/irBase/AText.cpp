#include "AText.h"

#include <QString>

#include <ctype.h>
#include <climits>

#include "ATextList.h"
#include "MetaType.h"
#include "TriBool.h"
#include "TypeFormat.h"

char AText::smHingeChar = ' ';

AText::AText(const char *pch) { set(pch); }
AText::AText(const char *pch, const QChar repl) { set(pch, repl); }
AText::AText(const char ch) { set(ch); }
AText::AText(const QByteArray &ba) { set(ba); }
AText::AText(const QByteArray &ba, const QChar repl) { set(ba, repl); }
AText::AText(const QString &aString) { set(aString); }
AText::AText(const Count k, const char ch) { set(k, ch); }
AText::AText(const QVariant &aVar) { set(aVar); }

AText::Pair AText::keyValue(const char ch) const
{
    AText tKey, tValue;
    Index ix = indexOf(ch);
    if (ix <= 0)
        tKey = mid(0);
    else if (ix >= length() - 1)
        tKey = mid(0), tValue = "";
    else
        tKey = first(ix - 1), tValue = mid(ix + 1);
    return Pair(tKey, tValue);
}


bool AText::isEmpty() const
{
    bool result = QByteArray::isEmpty();
    if ( ! result) result |= QByteArray::at(0) == '\0';
    return result;
}

bool AText::isValid(const Index ix) const
{
    return ix >= 0 && ix < length();
}

AText AText::formatted(const QVariantList vars) const
{
    return formatted(it(), vars);
}

AText AText::formatted(const QVariant var1, const QVariant var2,
                       const QVariant var3, const QVariant var4) const
{
    QVariantList vars;
    if (var1.isValid())     vars << var1;
    if (var2.isValid())     vars << var2;
    if (var3.isValid())     vars << var3;
    if (var4.isValid())     vars << var4;
    return formatted(vars);
}

AText::List AText::split(const char hinge) const
{
    QString tString(it());
    return ATextList(tString.split(hinge));
}

AText::List AText::split(const AText &hinge) const
{
    QString tString(it());
    return ATextList(tString.split(hinge));
}

AText AText::formattedList(const QVariantList vars) const
{
    return QString("%1 %2 %3 %4 %5 %6 %7 %8 %9")
        .arg(saveVarListString(vars, 0))
        .arg(saveVarListString(vars, 1))
        .arg(saveVarListString(vars, 2))
        .arg(saveVarListString(vars, 3))
        .arg(saveVarListString(vars, 4))
        .arg(saveVarListString(vars, 5))
        .arg(saveVarListString(vars, 6))
        .arg(saveVarListString(vars, 7))
        .arg(saveVarListString(vars, 9))
        .arg(saveVarListString(vars, 9));
}

AText AText::modified(const Modify mod) const
{
    AText result = it();
    result.set(mod);
    return result;
}

AText AText::sub(const IndexList ixs) const
{
    AText result;
    foreach (const Index ix, ixs)
        if (isValid(ix))
            result += QByteArray::at(ix);
    return result;
}

bool AText::equals(const AText &rhs) const
{
    QByteArray lhsBA = QByteArray(it());
    QByteArray rhsBA = QByteArray(rhs);
    return lhsBA == rhsBA;
}

bool AText::like(const AText &rhs, const Modify mod) const
{
    QByteArray lhsBA = modified(mod);
    QByteArray rhsBA = rhs.modified(mod);
    return lhsBA == rhsBA;
}

bool AText::less(const AText &rhs) const
{
    QByteArray lhsBA = QByteArray(it()).toLower();
    QByteArray rhsBA = QByteArray(rhs).toLower();
    return lhsBA < rhsBA;
}

void AText::set(const char ch)
{
    clear();
    append(isValidChar(ch) ? ch : '~');
}

void AText::set(const char *pch)
{
    set(pch, QChar());
}

void AText::set(const char *pch, const QChar repl)
{
    clear();
    if (nullptr == pch) return;                                 /*/=====\*/
    if (0 != *pch)
    {
        QByteArray::reserve(strlen(pch) + 1);
        QByteArray::append(isValidFirst(*pch) ? *pch : repl.cell());
        ++pch;
        while (*pch)
        {
            QByteArray::append(isValidChar(*pch) ? *pch : repl.cell());
            ++pch;
        }
    }
}

void AText::set(const Count k, const char ch)
{
    fill(ch, k);
}

void AText::set(const QVariant &aVar)
{
    Q_UNUSED(aVar);
    Q_ASSERT(!"Done"); // TODO
//    it() = AText::format(aVar);
}

void AText::set(const Modify mod)
{
    switch (mod)
    {
    case(Upper):    it() = it().toUpper();      break;
    case(CaseFold): Q_FALLTHROUGH();
    case(Lower):    it() = it().toLower();      break;
    default:        Q_UNREACHABLE();
    };
}

int AText::vprintf(const char *format, va_list vlist)
{
    const Count k = vsnprintf(NULL, 0, format, vlist);
    resize(k);
    return vsnprintf(data(), k, format, vlist);
}

AText AText::append(const AText &more)
{
    QByteArray::append(more);
    return it();
}

AText AText::append(const char ch)
{
    QByteArray::append(ch);
    return it();
}

AText AText::takeFirst(const Count k)
{
    AText result = QByteArray::first(k);
    removeFirst(k);
    return result;
}

void AText::removeFirst(const Count k)
{
    QByteArray::remove(0, k);
}

void AText::removeEach(const char ch)
{
    Index ix = lastIndexOf(ch);
    while (ix > -1)
        removeAt(ix);
}

void AText::removeEach(const AText &atx)
{
    foreach(const char ch, atx)
        removeEach(ch);
}

/*static*/ AText AText::formatDecimal(const QVariant aVar)
{
    AText result;
    const MetaType cMT = aVar.metaType();
    const TriBool cSign = cMT.isSigned();
    signed long long tSInt = 0;
    unsigned long long tUInt = 0;
    Index tStartIx = 0;
    QString tNumString;
    if (cSign.isTrue())
    {
        tSInt = aVar.toLongLong();
        tNumString = QString::number(tSInt);
        tStartIx = (tSInt < 0) ? 1 : 0;
    }
    else if (cSign.isFalse())
    {
        tUInt = aVar.toULongLong();
        tNumString = QString::number(tUInt);
    }
    else
    {
        ; // non integral, return nothing
    }
    if (tNumString.length() > 3)
        for (Index ix = tNumString.length(); ix > tStartIx; ix -= 3)
            tNumString.insert(ix, ",");
    return result = tNumString;
}

/*static*/ AText AText::formatHeximal(const QVariant aVar)
{
    AText result;
    result = QString::number(aVar.toUInt());
    return result;
}

/*static*/ AText AText::format(const AText aFormat, const QVariantList vars)
{
    AText result = aFormat;
    for (Index ix = 1; ix < Index(vars.count() - 1); ++ix)
    {
        AText tPctNum = QString("%") + QString::number(ix, 10);
        if (result.contains(tPctNum))
            result.replace(tPctNum.toQBAV(),
                           AText(AText("<")
                                 + TypeFormat(vars.at(ix))
                                 + AText(">")
                                 + AText(QString::number(ix, 10))));
    }
    return result;
}

AText AText::format(const AText aFormat, const QVariant var1, const QVariant var2, const QVariant var3, const QVariant var4)
{
    QVariantList vars;
    if (var1.isValid())     vars << var1;
    if (var2.isValid())     vars << var2;
    if (var3.isValid())     vars << var3;
    if (var4.isValid())     vars << var4;
    return format(aFormat, vars);
}


bool AText::isValidFirst(const char ch) const
{
    return isprint(ch);
}

bool AText::isValidChar(const char ch) const
{
    return isprint(ch);
}

QString AText::saveVarListString(const QVariantList &vars, const Index ix)
{
    return (ix >= 0 && ix < vars.count()) ? vars.at(ix).toString() : QString();
}

AText operator + (const AText &lhs, const AText &rhs)
{
    QString ls(lhs), rs(rhs);
    QString res(ls + rs);
    AText result(res);
    return result;
}

