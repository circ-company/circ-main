#include "Url.h"

#include <QtDebug>
#include <QDir>
#include <QMetaProperty>

//#include <ObjectHelper.h>

Url::Url() : mpType(new UrlType()) {;}
Url::Url(const QString &url, QUrl::ParsingMode mode) : mpType(new UrlType()) { set(url, mode); }

bool Url::isNull() const
{
    return mUrl.isEmpty() || type()->isNull();
}

bool Url::isValid() const
{
    return mUrl.isValid() && ! type()->isNull();
}

bool Url::isLocalFile() const
{
    qInfo() << Q_FUNC_INFO << mUrl.toString() << mUrl.isLocalFile() << mUrl.toLocalFile();
    bool result = false;
    QUrl tQUrl(mUrl);
    if (type()->file()) tQUrl.setScheme("file");
    if (tQUrl.isLocalFile())
    {
        const QString cFileString =  tQUrl.toLocalFile();
        QFileInfo tFI(cFileString);
        result |= tFI.isFile() && tFI.exists();
    }
    qInfo() << Q_FUNC_INFO << result << tQUrl << tQUrl.isLocalFile() << tQUrl.toLocalFile();
    return result;
}

bool Url::isLocalDir() const
{
    bool result = false;
    qInfo() << Q_FUNC_INFO << mUrl.toString() << mUrl.isLocalFile() << mUrl.toLocalFile();
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
    type()->nullify(), mUrl.clear(), mQuery.clear(), mQueryText.clear(),
        mQueryList.clear(), mQueryPairs.clear(), mQueryPairMMap.clear();
}

void Url::set(const QString &s, QUrl::ParsingMode mode)
{
    qInfo() << Q_FUNC_INFO << s << mode;
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
    if (type()->file())
    {
        mUrl.setScheme(mScheme = "file");
        mLocalFileInfo = QFileInfo(mUrl.toLocalFile());
        qDebug() << mUrl << mScheme << mLocalFileInfo;
    }
    mUsername = mUrl.userName();
    mPassword = mUrl.password();
    mHost = mUrl.host();
    mPort = mUrl.port();
    mPath = mUrl.path();
    mPathList = mPath.split(QDir::separator().cell());
    qInfo() << Q_FUNC_INFO << string() << scheme() << type()->name()
            << authority() << path() << pathCount() << pathDir()
            << localFlleInfo() << localDir() << queryMapList();
}

void Url::dir(const QDir &dir)
{
    mUrl.setPath(dir.path());
}

void Url::setScheme(const CText &scheme)
{
    type(scheme);
    mUrl.setScheme(scheme);
}

bool Url::type(const CText &scheme)
{
    bool result = !! mpType;
    if (result) result &= mpType->set(scheme);
    return result;
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




