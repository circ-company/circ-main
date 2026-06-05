#pragma once

#include <QObject>

#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QUrl>
#include <QUrlQuery>

#include <AText.h>
#include <ATextList.h>
#include <Types.h>

#include "UrlType.h"

class Url : public QObject
{
    Q_GADGET
public: // types
    typedef QList<Url> List;

    enum class Type : BYTE
    {
        $null = 0,
        $File ,             //  1-Begin File
        File = $File,       //  1
        Files,              //  2
        TextFile,           //  3
        $Dir ,              //  4-Begin Dir
        Dir = $Dir,         //  4
        WatchDir,           //  5
        $SQL ,              //  6-Begin SQL
        SQL = $SQL,         //  6
        SQLite,             //  7
        PgSQL,              //  8
        $max
    };

public: // ctors
    Url();
    Url(const QString &url, QUrl::ParsingMode mode=QUrl::TolerantMode);
    Url & operator = (const QString &url);


public: // const
    bool isNull() const;
    bool isValid() const;
    bool isLocalFile() const;
    bool isLocalDir() const;
    AText string() const;
    CText scheme() const;
    const UrlType * type() const;
    AText username() const;
    AText password() const;
    AText userinfo() const;
    AText host() const;
    WORD port() const;
    AText authority() const;
    AText path() const;
    AText path(const Index ix) const;
    Count pathCount() const;
    QString toString(const bool encoded=false) const;
    QDir pathDir() const;
    QFileInfo localFlleInfo() const;
    QDir localDir() const;
    bool contains(const AText &queryName) const;
    AText value(const AText &queryName) const;
    AText operator [] (const AText &queryName) const;
    ATextList queryMapList();

public: // non-const
    void clear();
    void set(const QString &s, QUrl::ParsingMode mode=QUrl::TolerantMode);
    void dir(const QDir &dir);
    void setScheme(const CText &scheme);
    bool type(const CText &scheme);
    UrlType * type();

public: // static
    QStringList list(const QString delimtedUrls, const QChar hinge=QChar(';'));

private:
    Url * it();

private:
    UrlType * mpType=nullptr;
    QUrl mUrl;
    QUrlQuery mQuery;
    AText mQueryText;
    ATextList mQueryList;
    ATextList::PairList mQueryPairs;
    ATextList::PairMMap mQueryPairMMap;
    QFileInfo mLocalFileInfo;
    QDir mLocalDir;

    AText mString;
    CText mScheme;
    AText mUsername;
    AText mPassword;
    AText mHost;
    WORD mPort;
    AText mPath;
    ATextList mPathList;
};

inline AText Url::string() const { return mString; }
inline CText Url::scheme() const { return mScheme; }
inline AText Url::operator [](const AText &queryName) const { return value(queryName); }
inline UrlType *Url::type() { Q_CHECK_PTR(mpType); return mpType; }
inline Url * Url::it() { return this; }
inline const UrlType *Url::type() const { Q_CHECK_PTR(mpType); return mpType; }
inline AText Url::username() const  { return mUsername; }
inline AText Url::password() const  { return mPassword; }
inline AText Url::path() const  { return mPath; }
inline Count Url::pathCount() const  { return mPathList.count(); }
inline QFileInfo Url::localFlleInfo() const  { return mLocalFileInfo; }


