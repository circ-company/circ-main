#include "QCoreTypeFormat.h"

#include <QFileInfo>
#include <QRect>
#include <QSize>

void QCoreTypeFormat::registerQCore()
{
    const int cTypeIdQFileInfo = qRegisterMetaType<QFileInfo>();
//    qDebug() << Q_FUNC_INFO << cTypeIdQFileInfo;
    Q_ASSERT(cTypeIdQFileInfo);

    registerFunction(QMetaType::QChar, &formatQChar);
    registerFunction(QMetaType::Char16, &formatQChar);
    registerFunction(QMetaType::QByteArray, &formatString);
    registerFunction(QMetaType::QString, &formatString);
    registerFunction(QMetaType::QBitArray, &formatHexData);
    registerFunction(QMetaType::QByteArray, &formatHexData);
    registerFunction(QMetaType::QSize, &formatQSize);
    registerFunction(QMetaType::QRect, &formatQRect);
    registerFunction(cTypeIdQFileInfo, &formatQFileInfo);
//  registerFunction(QMetaType::Char32, &formatQChar);
//  TODO howto: QMetaType::Char32
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
    result = QString("HEX[%1]:<%2>").arg(cBytes.length()).arg(cHexStr);
    return result;
}

AText QCoreTypeFormat::formatQSize(const QVariant &aVar)
{
    const QSize cSize = aVar.toSize();
    return AText::format("QSize(w%1, h%2)",
                         TypeFormat(cSize.height()),
                         TypeFormat(cSize.width()));
}

AText QCoreTypeFormat::formatQRect(const QVariant &aVar)
{
    const QRect cRect = aVar.toRect();
    return AText(QString("QRect(l%1, t%2, r%34, b%4)")
                         .arg(cRect.left())
                         .arg(cRect.top())
                         .arg(cRect.right())
                         .arg(cRect.bottom()));
}

AText QCoreTypeFormat::formatQFileInfo(const QVariant &aVar)
{
    const QFileInfo cFI = aVar.value<QFileInfo>();
    AText result = QString("QFileInfo:%1 exists=%2 read=%3 write=%4 modified=%5")
                       .arg(cFI.filePath())
                       .arg(cFI.exists())
                       .arg(cFI.isReadable())
                       .arg(cFI.isWritable())
                       .arg(cFI.lastModified().toString());
    return result;
}
