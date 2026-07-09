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
        $File,              //  1-Begin File
        File,               //  2
        Files,              //  3
        TextFile,           //  4
        $Dir,               //  5-Begin Dir
        Dir,                //  6
        WatchDir,           //  7
        $SQL,               //  8-Begin SQL
        SQL,                //  9
        SQLite,             // 10
        PgSQL,              // 11
        $max                // 12
    };

public: // ctors
    Url(const QString &aUrlStr, QUrl::ParsingMode mode=QUrl::TolerantMode);
    Url(const QString &aUrlStr, const Type aType);
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
    bool isNullType() const;
    bool fileType() const;
    bool dirType() const;
    bool sqlType() const;
    bool inRangeType(const Type &lo, const Type &hi) const;
    Type evalueType() const;
    BYTE valueType() const;
    CText nameType() const;
    operator QVariant() const;

public: // non-const
    void clear();
    void set(const QString &s, QUrl::ParsingMode mode=QUrl::TolerantMode);
    void dir(const QDir &dir);
    bool type(const CText &sch);
    void nullifyType();
    bool setType(const BYTE val);
    bool setType(const CText &nam);
    void setType(const Type other);

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


