#include "CppTypeFormat.h"

void CppTypeFormat::registerCpp()
{
    registerFunction(QMetaType::Void, &formatVoid);
    registerFunction(QMetaType::Nullptr, &formatVoid);
    registerFunction(QMetaType::VoidStar, &formatVoid);
    registerFunction(QMetaType::QObjectStar, &formatVoid);
    registerFunction(QMetaType::Bool, &formatBool);
    registerFunction(QMetaType::Int, &formatSigned);
    registerFunction(QMetaType::UInt, &formatUnsigned);
    registerFunction(QMetaType::Char, &formatChar);
    registerFunction(QMetaType::Float, &formatFloat);
    registerFunction(QMetaType::Float16, &formatFloat);

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
    const AText cTxt = aVar.toString();
    const AText cDec = AText::formatDecimal(aVar);
    const AText cHex = AText::formatHeximal(aVar);
    return AText(QString("%1=%2 <%3>").arg(cDec, cHex, cTxt));
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
    const AText cAtxChar((char)aVar.toChar().cell());
    return AText(QString("char:%1(%2 0x%3)")
                     .arg(cAtxChar())
                     .arg(aVar.toUInt(), 3, u'0')
                     .arg(QString::number(aVar.toUInt(), 16), 2, u'0'));
}

AText CppTypeFormat::formatFloat(const QVariant &aVar)
{
    AText result;
    const qreal cFloat = aVar.toDouble();
    const signed cLog10 = log10(cFloat);
    if (qIsNaN(cFloat))
    {
        result.set("float:NAN");
    }
    else if (qIsInf(cFloat))
    {
        result.set("float:INF");
    }
    else if (-10 < cLog10 && cLog10 < +10)
    {
        QString cStrFloat = QString::number(cFloat, 'f', 6);
        result.set(cStrFloat);
    }
    else
    {
        QString cStrFloat = QString::number(cFloat, 'e', 6);
        result.set(cStrFloat);
    }
    return result;
}

