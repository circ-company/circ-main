#pragma once

#include <QObject>

#include <KeyMap.h>
#include <Result.h>
#include <Url.h>

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
    void set(const Url &url);
    void set(const QString &url);
    void read();
    void parse();

signals:
    void urlSet(const Url &url);
    void urlRead(const Url &url, const Result &aResult);
    void parsed(const Url &url, const Result &aResult);

public: // const
    EntryList list(const cvODClass cls, const cvODType type);

public: // non-const

private:
    Url mUrl;
    QDomDocument mDomDocument;
    KeyMapT<cvODCatalogEntry> mEntryMap;
};
