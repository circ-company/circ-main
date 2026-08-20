#include "Image.h"

#include <QByteArray>
#include <QDataStream>

QImage::Format Image::smQIFormat = QImage::Format_Invalid;

Image::Image(const FileInfo &aFI)
{
    qRegisterMetaType(QMetaType::fromName("Image"));
    set(aFI);
}

QVariant Image::toVariant() const
{
    QVariant result;
    QByteArray tBytes;
    QDataStream tDS(tBytes);
    tDS << mFileInfo.toData();
    result.setValue(tBytes);
    return result;
}

void Image::clear()
{
    mQImage = QImage();
    mFileInfo.nullify();
}

bool Image::set(const FileInfo &aFI)
{
    bool result = false;
    if ( ! aFI.isNull() && aFI.exists() && aFI.isReadable())
    {
        QImage tImage(aFI.filePath());
        if ( ! tImage.isNull())
        {
            tImage.convertTo(baseColorFormat());
            if ( ! tImage.isNull())
            {
                mFileInfo = aFI;
                mFileKey = mFileInfo.key();
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

QImage::Format Image::baseColorFormat()
{
    return smQIFormat ? smQIFormat : QImage::Format_ARGB32;
}

void Image::setColorFormat(const QImage::Format aQIF)
{
    if (aQIF != QImage::Format_Invalid)
        smQIFormat = aQIF;
}
