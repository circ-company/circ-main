#pragma once

#include <QDomDocument>

//#include <QDomElement>
#include <QIODevice>

#include <QMetaType>

#include <TextFile.h>
#include <FileInfo.h>
#include <KeyMap.h>
#include <Status.h>

#include "XmlElement.h"

class XmlDocument : public QDomDocument
{
public: // types

public: // ctors
    XmlDocument(const FileInfo &aFI);

public: // const
    bool isOpen() const;

public: // non-const
    bool set(const FileInfo &aFI);
    Status open(const QIODevice::OpenMode aMode);
    void close();
    Status read();
    Status parse();

public: // pointers

private:
    FileInfo mFileInfo;
    TextFile * mpFile;
    XmlElement mRootElement;
    KeyMap mXmlMap;

public: // QMetaType
    XmlDocument() = default;
    ~XmlDocument() = default;
    XmlDocument(const XmlDocument &) = default;
    XmlDocument &operator=(const XmlDocument &) = default;
    XmlDocument & it() { return *this; }
    const XmlDocument & it() const { return *this; }
};

Q_DECLARE_METATYPE(XmlDocument);
