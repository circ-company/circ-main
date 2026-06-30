#include "CppTypeFormat.h"

void CppTypeFormat::registerCpp()
{
    registerFunction(QMetaType::Void, &formatVoid);
    registerFunction(QMetaType::Bool, &formatBool);
    registerFunction(QMetaType::Int, &formatSigned);
    registerFunction(QMetaType::UInt, &formatUnsigned);
    registerFunction(QMetaType::Char, &formatChar);
    registerFunction(QMetaType::Char16, &formatUChar);
    registerFunction(QMetaType::QChar, &formatUChar);
    registerFunction(QMetaType::QByteArray, &formatString);
    registerFunction(QMetaType::QString, &formatString);
}

AText CppTypeFormat::formatVoid(const QVariant &aVar)
{
    Q_UNUSED(aVar);
    return "void:";
}

AText CppTypeFormat::formatBool(const QVariant &aVar)
{
    return AText("bool:") + AText(aVar.toBool() ? "true" : "false");
}

AText CppTypeFormat::formatSigned(const QVariant &aVar)
{
    const AText cDec = AText::formatDecimal(aVar);
    const AText cHex = AText::formatHeximal(aVar);
    return AText(QString("%1=%2").arg(cDec, cHex));
}

AText CppTypeFormat::formatUnsigned(const QVariant &aVar)
{
    return AText(QString::number(aVar.toUInt()));
}

AText CppTypeFormat::formatChar(const QVariant &aVar)
{
    const AText cAtxChar((char)aVar.toChar().cell());
    return AText(QString("char:%1(%2 0x%3)")
                     .arg(cAtxChar())
                     .arg(aVar.toUInt(), 3, u'0')
                     .arg(QString::number(aVar.toUInt(), 16), 2, u'0'));
}

AText CppTypeFormat::formatUChar(const QVariant &aVar)
{
    const QChar cQChar = aVar.toChar();
    const AText cAtxChar((char)cQChar.cell());
    return AText(QString("char:%1(%2,%3 0x%4)")
                     .arg(cAtxChar())
                     .arg(cQChar.row(), 3, u'0')
                     .arg(cQChar.cell(), 3, u'0')
                     .arg(QString::number(aVar.toUInt(), 16), 4, u'0'));
}

AText CppTypeFormat::formatString(const QVariant &aVar)
{
    return AText(aVar.toString());
}
