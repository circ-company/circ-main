#include "AText.h"

#include <QDate>
#include <QDateTime>
#include <QTime>
#include <QUrl>
#include <QLocale>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QSizeF>
#include <QLine>
#include <QLineF>
#include <QPoint>
#include <QPointF>
#include <QUuid>
#include <QCborArray>
#include <QCborMap>
#include <QCborValue>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>


AText AText::formatted(const AText aFormat, const QVariantList vars)
{
    AText result = aFormat;
    for (Index ix = 1; ix < Index(vars.count()); ++ix)
    {
        AText tPctNum = QString("%") + QString::number(ix, 10);
        if (result.contains(tPctNum))
            result.replace(tPctNum.toQBAV(),
                           AText(AText("<")+format(vars.at(ix))
                                 +AText(">")+AText(QString::number(ix, 10))));
    }
    return result;
}

AText AText::format(const QVariant aVar)
{
    const QMetaType cMetaType = aVar.metaType();
    QString result = QString("{MetaType=%1(%2)}").arg(cMetaType.name()).arg(cMetaType.id());

    const QRect cRect = aVar.toRect();
    const QSize cSize = aVar.toSize();
    switch (cMetaType.id())
    {
    case QMetaType::Bool:   result = aVar.toBool() ? "<bool:true>" : "<bool:false>";    break;
    case QMetaType::Short:  Q_FALLTHROUGH();
    case QMetaType::Long:   Q_FALLTHROUGH();
    case QMetaType::Int:    result = QString::number(aVar.toInt());                     break;
    case QMetaType::UShort:  Q_FALLTHROUGH();
    case QMetaType::ULong:   Q_FALLTHROUGH();
    case QMetaType::QCborSimpleType:   Q_FALLTHROUGH();
    case QMetaType::UInt:    result = QString::number(aVar.toUInt());                     break;
    case QMetaType::LongLong:    result = QString::number(aVar.toLongLong());                     break;
    case QMetaType::ULongLong:    result = QString::number(aVar.toULongLong());                     break;
    case QMetaType::QObjectStar:        Q_FALLTHROUGH();
    case QMetaType::VoidStar:        Q_FALLTHROUGH();
    case QMetaType::Nullptr:    result = "0x"+QString::number(aVar.toULongLong(), 16);                     break;
    case QMetaType::Float:    result = QString::number(aVar.toFloat());                     break;
    case QMetaType::Double:    result = QString::number(aVar.toDouble());                     break;
    case QMetaType::QChar:   Q_FALLTHROUGH();
    case QMetaType::Char:   Q_FALLTHROUGH();
    case QMetaType::SChar:  Q_FALLTHROUGH();
    case QMetaType::UChar:    Q_FALLTHROUGH();
    case QMetaType::Char16: Q_FALLTHROUGH();
    case QMetaType::Char32:     result = AText(char(aVar.toChar().cell()));                     break;
    case QMetaType::QString:     result = aVar.toString();                     break;
    case QMetaType::QDate:     result = aVar.toDate().toString();                     break;
    case QMetaType::QTime:     result = aVar.toTime().toString();                     break;
    case QMetaType::QDateTime:     result = aVar.toDateTime().toString();                     break;
    case QMetaType::QLocale:     result = aVar.toLocale().name();                     break;
    case QMetaType::QRect:
        result = QString("QRect(T%1, L%2, B%3, R%4").arg(cRect.top()).arg(cRect.left()).arg(cRect.bottom()).arg(cRect.right());                     break;
    case QMetaType::QSize:
        result = QString("QSize(W%1, H%2").arg(cSize.width()).arg(cSize.height());                     break;
        /* I'm bored */
        // TODO



    case QMetaType::QBitArray:        Q_FALLTHROUGH();
    case QMetaType::QByteArray:
        /* Future HexDump.join(Qt::newl() */ break;

    case QMetaType::QByteArrayList:        Q_FALLTHROUGH();
    case QMetaType::QStringList:        Q_FALLTHROUGH();
    case QMetaType::QKeySequence:        Q_FALLTHROUGH();
    case QMetaType::QVariant:        Q_FALLTHROUGH();
    case QMetaType::QVariantMap:        Q_FALLTHROUGH();
    case QMetaType::QVariantList:        Q_FALLTHROUGH();
    case QMetaType::QVariantHash:        Q_FALLTHROUGH();
    case QMetaType::QVariantPair:        Q_FALLTHROUGH();
    case QMetaType::QEasingCurve:        Q_FALLTHROUGH();
    case QMetaType::QModelIndex:        Q_FALLTHROUGH();
    case QMetaType::QPersistentModelIndex:        Q_FALLTHROUGH();
    case QMetaType::QRegularExpression:        Q_FALLTHROUGH();
    case QMetaType::QUrl:        Q_FALLTHROUGH();
    case QMetaType::Void:
    default:                   /* UNHANDLED! */ break;
    }
    return AText(result);
}
