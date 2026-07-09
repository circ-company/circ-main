#include "Url.h"

#include <QtDebug>
#include <QDir>
#include <QVariant>

Url::Url(const QString &aUrlStr, QUrl::ParsingMode mode)
    : mType(Type::$null) { set(aUrlStr, mode); }
Url::Url(const QString &aUrlStr, const Type aType)
    : mType(aType) { set(aUrlStr); setType(aType); }

bool Url::isNull() const
{
    return mUrl.isEmpty() || isNullType();
}

bool Url::isValid() const
{
    return mUrl.isValid() && ! isNullType();
}

bool Url::isLocalFile() const
{
  //  qInfo() << Q_FUNC_INFO << mUrl.toString() << mUrl.isLocalFile() << mUrl.toLocalFile();
    bool result = false;
    QUrl tQUrl(mUrl);
    if (fileType()) tQUrl.setScheme(nameType());
    if (tQUrl.isLocalFile())
    {
        const QString cFileString =  tQUrl.toLocalFile();
        QFileInfo tFI(cFileString);
        result |= tFI.isFile() && tFI.exists();
    }
//    qInfo() << Q_FUNC_INFO << result << tQUrl << tQUrl.isLocalFile() << tQUrl.toLocalFile();
    return result;
}

bool Url::isLocalDir() const
{
    bool result = false;
//    qInfo() << Q_FUNC_INFO << mUrl.toString() << mUrl.isLocalFile() << mUrl.toLocalFile();
    if (isLocalFile())
    {
        const QString cFileString =  localFlleInfo().path();
        QFileInfo tFI(cFileString);
        if (tFI.isDir())
        {
            QDir tDir(cFileString);
            result |= tDir.isReadable();
        }
    }
    return result;
}

AText Url::authority() const
{
    return username() + AText(":") + password();
}

QString Url::toString(const bool encoded) const
{
    QUrl tUrl = mUrl;
    tUrl.setQuery(mQuery);
    return encoded ? tUrl.toEncoded() : tUrl.toString();
}

QDir Url::pathDir() const
{
    return QDir(mUrl.path());
}

QDir Url::localDir() const
{
    QDir result;
    if (isLocalFile())
    {
        const QString cFileString =  mUrl.toLocalFile();
        QFileInfo tFI(cFileString);
        if (tFI.isDir())
            result = QDir(cFileString);
    }
    return result;
}

bool Url::contains(const AText &queryName) const
{
    return mQueryPairMMap.contains(queryName);
}

AText Url::value(const AText &queryName) const
{
    return mQueryPairMMap.value(queryName);
}

ATextList Url::queryMapList()
{
    return ATextList::toList(mQueryPairMMap);
}

void Url::clear()
{
    nullifyType(), mUrl.clear(), mQuery.clear(), mQueryText.clear(),
        mQueryList.clear(), mQueryPairs.clear(), mQueryPairMMap.clear();
}

void Url::set(const QString &s, QUrl::ParsingMode mode)
{
//    qInfo() << Q_FUNC_INFO << s << mode;
    clear();
    mUrl.setUrl(s, mode);
    mQuery.setQuery(mUrl.query());
    mUrl.setQuery("");

    mQueryText = mQuery.toString();
    if ( ! mQueryText.isEmpty())
    {
        mQueryList = mQueryText.split('&');
        mQueryPairs = mQueryList.ATextList::splitPairs('=');
        foreach (const AText::Pair cPair,  mQueryPairs)
        {
            const AText cName = cPair.first;
            const AText cValue = cPair.second;
            mQueryPairMMap.insert(cName, cValue);
        }
    }

    mString = s;
    mScheme = mUrl.scheme();
    type(scheme());
    if (fileType())
    {
        mUrl.setScheme(mScheme = "file");
        mLocalFileInfo = QFileInfo(mUrl.toLocalFile());
//        qDebug() << mUrl << mScheme << mLocalFileInfo;
    }
    mUsername = mUrl.userName();
    mPassword = mUrl.password();
    mHost = mUrl.host();
    mPort = mUrl.port();
    mPath = mUrl.path();
    mPathList = mPath.split(QDir::separator().cell());
//    qDebug() << Q_FUNC_INFO << string() << scheme() << nameType()
  //          << authority() << path() << pathCount() << pathDir()
    //        << localFlleInfo() << localDir() << queryMapList();
}

void Url::dir(const QDir &dir)
{
    mUrl.setPath(dir.path());
}

bool Url::type(const CText &sch)
{
    bool result = ! sch.isEmpty();
    if (result) result &= setType(sch);
    if (result) mUrl.setScheme(nameType());
    return result;
}

bool Url::inRangeType(const Type &lo, const Type &hi) const
{
    return Utility::inRange(lo, mType, hi);
}

CText Url::nameType() const
{
    return QVariant(mType).toString();
}

Url::operator QVariant() const
{
    QVariant result;
    QUrl tQUrl = mUrl;
    tQUrl.setQuery(mQuery);
    result.setValue(tQUrl);
    return result;
}

bool Url::setType(const CText &nam)
{
    mType = Type(Utility::fromName($null, nam, $max));
    return inRangeType($null, $max);
}

QStringList Url::list(const QString delimtedUrls, const QChar hinge)
{
    QStringList result;
    foreach (QString s, delimtedUrls.split(hinge))
    {
        Url tUrl(s);
        if (tUrl.isValid())
            result << s;
    }
    return result;
}




