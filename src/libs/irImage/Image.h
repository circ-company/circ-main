#pragma once

#include <QMetaType>
#include <QImage>
#include <QVariant>

#include <FileInfo.h>
#include <Key.h>

class Image
{
public: // ctors
    Image(const FileInfo &aFI);

public: // const
    bool isNull() const;
    FileInfo fileInfo() const;
    Key fileKey() const;
    QImage toQImage() const;
    QVariant toVariant() const;

public: // non-const
    void clear();
    bool set(const FileInfo &aFI);


public: // static
    static QImage::Format baseColorFormat();
    static void setColorFormat(const QImage::Format aQIF);
    static QString openFileFilters();


public: // pointers
    QImage operator () () const;
    operator QImage () const;

public: // debug

private:
    QImage mQImage;
    FileInfo mFileInfo;
    Key mFileKey;
    static QImage::Format smQIFormat;

public: // QMetaType
    Image() = default;
    ~Image() = default;
    Image(const Image &) = default;
    Image &operator=(const Image &) = default;
    Image & it() { return *this; }
    const Image & it() const { return *this; }
};

Q_DECLARE_METATYPE(Image);

inline bool Image::isNull() const { return mQImage.isNull() || fileInfo().isNull(); }
inline QImage Image::toQImage() const { return mQImage; }
inline FileInfo Image::fileInfo() const { return mFileInfo; }
inline Key Image::fileKey() const { return mFileKey; }
inline Image::operator QImage() const { return toQImage(); }
inline QImage Image::operator ()() const { return toQImage(); }

