#include "QGuiTypeFormat.h"

#include <QImage>

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
        .arg(tImage.width())
        .arg(tImage.format());
}
