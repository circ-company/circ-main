#include "Image.h"

#include <QByteArray>
#include <QDataStream>

QImage::Format Image::smQIFormat = QImage::Format_Invalid;

Image::Image(const QFileInfo &aFI)
{
    qRegisterMetaType(QMetaType::fromName("Image"));
    set(aFI);
}

QVariant Image::toVariant() const
{
    QVariant result;
    QByteArray tBytes;
    QDataStream tDS(tBytes);
//    tDS << mFileInfo.toData();
    result.setValue(tBytes);
    return result;
}

void Image::clear()
{
    mId.clear();
    mQImage = QImage();
}

bool Image::set(const QFileInfo &aFI)
{
    bool result = false;
    if ( /*! aFI.isNull() &&*/ aFI.exists() && aFI.isReadable())
    {
        QImage tImage(aFI.filePath());
        if ( ! tImage.isNull())
        {
            tImage.convertTo(baseColorFormat());
            if ( ! tImage.isNull())
            {
                mFileInfo = aFI;
                mId.key(mFileInfo.filePath());
                mQImage = tImage;
                result = true;
            }
        }
    }
    return result;
}

// ---------------------- static -----------------------

QString Image::openFileFilters()
{
    // TODO ImageIOFormats class, etc.
    QString result;
    result = "JPEG Images (*.jpg);;PNG Images (*.png);;Images (*.jpg *.png)";
    return result;
}

QStringList Image::dirEntryFilters()
{
    // TODO ImageIOFormats class, etc.
    QStringList result;
    result << "*.jpg";
    result << "*.png";
    return result;
}

QImage::Format Image::baseColorFormat()
{
    return smQIFormat ? smQIFormat : QImage::Format_ARGB32;
}

void Image::setColorFormat(const QImage::Format aQIF)
{
    if (aQIF != QImage::Format_Invalid)
        smQIFormat = aQIF;
}
