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
    TextFile * mpFile;
    XmlElement mRootElement;
    KeyMapT<XmlElement> mKeyElementMap;

public: // QMetaType
    XmlDocument() = default;
    ~XmlDocument() = default;
    XmlDocument(const XmlDocument &) = default;
    XmlDocument &operator=(const XmlDocument &) = default;
    XmlDocument & it() { return *this; }
    const XmlDocument & it() const { return *this; }
};

inline XmlElement XmlDocument::rootElement() const { return mRootElement; }
inline QString XmlDocument::rootTag() const { return rootElement().tagName(); }

Q_DECLARE_METATYPE(XmlDocument);
