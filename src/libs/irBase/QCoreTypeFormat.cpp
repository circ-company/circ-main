#include "QCoreTypeFormat.h"

void QCoreTypeFormat::registerQCore()
{
    const int cTypeIdAText = QMetaType::fromName("AText").id();
    qDebug() << Q_FUNC_INFO << cTypeIdAText;

    registerFunction(QMetaType::QChar, &formatQChar);
    registerFunction(QMetaType::Char16, &formatQChar);
    registerFunction(QMetaType::QByteArray, &formatString);
    registerFunction(QMetaType::QString, &formatString);
    registerFunction(QMetaType::QBitArray, &formatHexData);
    registerFunction(QMetaType::QByteArray, &formatHexData);

    // unknown: QMetaType::Char32
}

AText QCoreTypeFormat::formatQChar(const QVariant &aVar)
{
    const QChar cQChar = aVar.toChar();
    const AText cAtxChar((char)cQChar.cell());
    return AText(QString("char:%1(%2,%3 0x%4)")
                     .arg(cAtxChar())
                     .arg(cQChar.row(), 3, u'0')
                     .arg(cQChar.cell(), 3, u'0')
                     .arg(QString::number(aVar.toUInt(), 16), 4, u'0'));
}

AText QCoreTypeFormat::formatString(const QVariant &aVar)
{
    const QString cString = aVar.toString();
    return AText(QString("<%1>(%2)").arg(cString).arg(cString.length()));
}

AText QCoreTypeFormat::formatHexData(const QVariant &aVar)
{
    AText result;
    QByteArray cBytes = aVar.toByteArray();
    QString cHexStr = AText(cBytes.toHex());
    cHexStr.truncate(64);
    result = QString("bytes(%1):%2").arg(cBytes.length()).arg(cHexStr);
    return result;
}
