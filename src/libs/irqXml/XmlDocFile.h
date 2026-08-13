#pragma once

#include <QDomDocument>

#include <QIODevice>

#include <QMetaType>

#include <TextFile.h>
#include <FileInfo.h>
#include <KeyMap.h>
#include <Status.h>

#include "XmlElement.h"

class XmlDocFile : public QDomDocument
{
public: // types

public: // ctors
    XmlDocFile(const FileInfo &aFI);

public: // const
    bool isOpen() const;
    XmlElement rootElement() const;
    QString rootTag() const;

public: // non-const
    bool set(const FileInfo &aFI);
    Status open(const QIODevice::OpenMode aMode);
    void close();
    Status read();
    Status parse();

public: // pointers

private: // non-const
    bool parse(const XmlElement &aParentXE, const Key &aParentKey);

private:
    FileInfo mFileInfo;
    TextFile * mpFile=nullptr;
    XmlElement mRootElement;
    KeyMapT<XmlElement> mKeyElementMap;

public: // QMetaType
    XmlDocFile() = default;
    ~XmlDocFile() = default;
    XmlDocFile(const XmlDocFile &) = default;
    XmlDocFile &operator=(const XmlDocFile &) = default;
    XmlDocFile & it() { return *this; }
    const XmlDocFile & it() const { return *this; }
};

inline XmlElement XmlDocFile::rootElement() const { return mRootElement; }
inline QString XmlDocFile::rootTag() const { return rootElement().tagName(); }

Q_DECLARE_METATYPE(XmlDocFile);
