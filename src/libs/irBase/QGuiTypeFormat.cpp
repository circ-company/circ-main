#include "QGuiTypeFormat.h"

#include <QImage>

static QString qiFormatName(const QImage::Format qif)
{
    QString result = QString("Unknown: %1").arg(int(qif));
    switch (qif)
    {

    };
    return result;
}

void QGuiTypeFormat::registerQGui()
{
    registerFunction(QMetaType::QBitArray, &formatImage);

}

AText QGuiTypeFormat::formatImage(const QVariant &aVar)
{
    QImage tImage = aVar.value<QImage>();
    return QString("Image: size(W%1,H%2) format(%3 #%4)")
        .arg(tImage.width())
        .arg(tImage.height())
        .arg(qiFormatName(tImage.format()))
        .arg(tImage.format());
}
