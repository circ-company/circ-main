#pragma once

#include <QObject>

#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QUrl>
#include <QUrlQuery>

#include <AText.h>
#include <ATextList.h>
#include <CText.h>
#include <Types.h>
#include <Utility.h>


class Url
{
public: // types
    typedef QList<Url> List;

    enum Type : BYTE
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
    Url(const QString &url, QUrl::ParsingMode mode=QUrl::TolerantMode);
    Url & operator = (const QString &url);


public: // const
    bool isNull() const;
    bool isValid() const;
    bool isLocalFile() const;
    bool isLocalDir() const;
    AText string() const;
    CText scheme() const;
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
    QString localFllePath() const;
    QFileInfo localFlleInfo() const;
    QDir localDir() const;
    bool contains(const AText &queryName) const;
    AText value(const AText &queryName) const;
    AText operator [] (const AText &queryName) const;
    ATextList queryMapList();
    Type type() const;

public: // non-const
    void clear();
    void set(const QString &s, QUrl::ParsingMode mode=QUrl::TolerantMode);
    void dir(const QDir &dir);
    bool type(const CText &sch);

    // ------------------------ enum class Type ------------------------
public: // const
    bool isNullType() const;
    bool fileType() const;
    bool dirType() const;
    bool sqlType() const;
    bool inRangeType(const Type &lo, const Type &hi) const;
    Type evalueType() const;
    BYTE valueType() const;
    CText nameType() const;

public: // non-const
    void nullifyType();
    bool setType(const BYTE val);
    bool setType(const CText &nam);
    void setType(const Type other);

private:

public: // static
    QStringList list(const QString delimtedUrls, const QChar hinge=QChar(';'));

private:
    Type mType=Type::$null;
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

public: // QMetaType
    Url() = default;
    ~Url() = default;
    Url(const Url &) = default;
    Url &operator=(const Url &) = default;
    const Url & it() const { return *this; }
};

Q_DECLARE_METATYPE(Url);

inline AText Url::string() const { return mString; }
inline CText Url::scheme() const { return mScheme; }
inline AText Url::operator [](const AText &queryName) const { return value(queryName); }
inline bool Url::isNullType() const { return Type::$null == mType; }
inline bool Url::fileType() const { return inRangeType(Type::$File, Type::$Dir); }
inline bool Url::dirType() const { return inRangeType(Type::$Dir, Type::$SQL); }
inline bool Url::sqlType() const { return inRangeType(Type::$SQL, Type::$max); }
inline Url::Type Url::type() const { return mType; }
inline AText Url::username() const  { return mUsername; }
inline AText Url::password() const  { return mPassword; }
inline AText Url::path() const  { return mPath; }
inline Count Url::pathCount() const  { return mPathList.count(); }
inline QString Url::localFllePath() const { return localFlleInfo().filePath(); }
inline QFileInfo Url::localFlleInfo() const  { return mLocalFileInfo; }


inline Url::Type Url::evalueType() const { return mType; }
inline BYTE Url::valueType() const { return BYTE(mType); }
inline void Url::nullifyType() { mType = Type::$null; }
inline void Url::setType(const Type other) { mType = other; }


