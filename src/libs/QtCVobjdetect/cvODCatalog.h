#pragma once

#include <QObject>

#include <FileInfo.h>
#include <KeyMap.h>
#include <Status.h>
#include <Url.h>
#include <XmlDocObject.h>

#include "cvODCatalogEntry.h"

class cvODCatalog : public QObject
{
    Q_OBJECT
public: // types
    typedef cvODCatalogEntry::List EntryList;

public: // c'tor
    explicit cvODCatalog(QObject *parent = nullptr);
    explicit cvODCatalog(const FileInfo &aFI, QObject *parent = nullptr);

public slots:
    void clear();
    void read();
    void injest();

signals:

public: // const
    FileInfo fileInfo() const;
    EntryList list(const cvODObjectClass cls, const cvODResourceType type);

public: // non-const
    void set(const FileInfo aFI);
    void injest(const KeySeg aType);


private: // non-const

private:
    FileInfo mFileInfo;
    KeyTextMap mFileMap;
    KeyMapT<cvODCatalogEntry> mEntryMap;
};

inline FileInfo cvODCatalog::fileInfo() const { return mFileInfo; }
inline void cvODCatalog::set(const FileInfo aFI) { mFileInfo = aFI; }
