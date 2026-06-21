#pragma once

#include <QDomDocument>

#include <QDomElement>

#include <QMetaType>

#include <File.h>
#include <FileInfo.h>
#include <KeyMap.h>
class Result;

#include "XmlElement.h"
//#include "XmlElementList.h"

class XmlDocument : public QDomDocument
{
public: // types

public: // ctors
    XmlDocument(const FileInfo &aFI);

public: // const
    bool isOpen() const;

public: // non-const
    bool set(const FileInfo &aFI);
    void close();
    Result readAll();

public: // pointers

private:
    FileInfo mFileInfo;
    File * mpFile;
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
