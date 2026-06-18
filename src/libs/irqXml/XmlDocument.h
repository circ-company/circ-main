#pragma once

#include <QDomDocument>

#include <QDomElement>

#include <QMetaType>

#include <File.h>
#include <FileInfo.h>

#include "XmlElement.h"
#include "XmlElementList.h"

class XmlDocument : public QDomDocument
{
public: // types

public: // ctors
    XmlDocument(const FileInfo &fi);

public: // const

public: // non-const

public: // pointers

private:
    FileInfo mFileInfo;
    File mFile;
    XmlElement mRootElement;
    XmlElementList mTopElements;

public: // QMetaType
    XmlDocument() = default;
    ~XmlDocument() = default;
    XmlDocument(const XmlDocument &) = default;
    XmlDocument &operator=(const XmlDocument &) = default;
    XmlDocument & it() { return *this; }
    const XmlDocument & it() const { return *this; }
};

Q_DECLARE_METATYPE(XmlDocument);
