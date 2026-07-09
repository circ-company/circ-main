#pragma once

#include <QObject>

#include <FileInfo.h>
#include <KeyMap.h>
#include <Status.h>
#include <Url.h>
#include <XmlDocument.h>

#include "cvODCatalogEntry.h"

class cvODCatalog : public QObject
{
    Q_OBJECT
public: // types
    typedef cvODCatalogEntry::List EntryList;

public: // c'tor
    explicit cvODCatalog(QObject *parent = nullptr);
    explicit cvODCatalog(const QString &url, QObject *parent = nullptr);
    explicit cvODCatalog(const Url &url, QObject *parent = nullptr);

public slots:
    void clear();
    void set(const Url &aUrl);
    void set(const QString &aUrlString);

signals:
    void urlSet(const Url &url);
    void urlRead(const Url &url, const Status &aStatus);
    void parsed(const Url &url, const Status &aStatus);

public: // const
    Url url() const;
    FileInfo fileInfo() const;
    EntryList list(const cvODObjectClass cls, const cvODResourceType type);

public: // non-const
    Status read();
    Status parse();

private:
    Url mUrl;
    FileInfo mFileInfo;
    XmlDocument mXmlDocument;
    KeyMapT<cvODCatalogEntry> mEntryMap;
};

inline Url cvODCatalog::url() const { return mUrl; }
inline FileInfo cvODCatalog::fileInfo() const { return mFileInfo; }
