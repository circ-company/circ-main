#include "XmlDocObject.h"

#include <QTimer>

#include <FileInfo.h>
#include <Log.h>

XmlDocObject::XmlDocObject(QObject *parent)
    : QObject{parent}
{
}

XmlDocObject::XmlDocObject(const FileInfo &aFileInfo, QObject *parent)
    : QObject{parent}
    , mFileInfo(aFileInfo)
{
    ctor();
}

XmlDocObject::XmlDocObject(const FSText &aFilePathName, QObject *parent)
    : QObject{parent}
    , mFileInfo(FileInfo(aFilePathName))
{
    ctor();
}

XmlDocObject::XmlDocObject(const QDir &aDir, const QString &aFileName, QObject *parent)
    : QObject{parent}
    , mFileInfo(FileInfo(aDir, aFileName))
{
    ctor();
}

void XmlDocObject::ctor()
{
    qRegisterMetaType<FileInfo>();
    setObjectName("XmlDocObject:" + mFileInfo.toString());
}

void XmlDocObject::clear()
{
    mStatus.clear();
    mFileInfo.nullify();
    mBytes.clear();
    mDocument.clear();
    mRootElement.clear();
    mPendingKeyElements.clear();
    mKeyMap.clear();
    emit cleared();
    emit level(mStatus.level());
    emit status(mStatus);
}

void XmlDocObject::set(const FileInfo &aFileInfo)
{
    mFileInfo = aFileInfo;
    emit fileSet(mFileInfo);
    if ( ! mFileInfo.exists()
            || ! mFileInfo.isReadable()
            || ! mFileInfo.isFile())
    {
        mStatus.set(StatusLevel::Error, QString("Expected "
                        "existing readable file: %1 in $2")
                        .arg(mFileInfo.baseName())
                        .arg(mFileInfo.dir().path()));
        emit level(mStatus.level());
        emit error(mStatus.level());
        emit status(mStatus);
    }
    else
    {
        emit fileSet(mFileInfo);
    }
}

void XmlDocObject::set(const FSText &aFilePathName)
{
    set(FileInfo(aFilePathName));
}

void XmlDocObject::set(const QDir &aDir, const QString &aFileName)
{
    set(FileInfo(aDir, aFileName));
}

bool XmlDocObject::read(const FileInfo &aFileInfo)
{
    set(aFileInfo);
    return read();
}

bool XmlDocObject::read()
{
    FNENTER();
    DUMPVAR(mFileInfo);
    QFile * pFile = new QFile(mFileInfo.filePath(), this);
    NEWOBJ(pFile, QFile, this);
    if (pFile)
    {
        bool ok = pFile->open(QIODevice::ReadOnly
                             | QIODevice::ExistingOnly
                             | QIODevice::Text);
        if (ok)
        {
            mBytes = pFile->readAll();
            DUMPVAR(pFile->size());
            DUMPVAR(mBytes.length());
            WEXPECTEQ(pFile->size(), mBytes.length());
            emit fileRead(mFileInfo);
            emit dataRead(mBytes);
            QTimer::singleShot(100, &XmlDocObject::startParse);
        }
        else
        {
            mStatus.set(StatusLevel::Error, pFile);
            emit level(mStatus.level());
            emit error(mStatus.level());
            WASSERT(ok);
        }
        pFile->close();
        pFile->deleteLater();
    }
    else
    {
        mStatus.set(StatusLevel::Error, QString("Unable to open file object: %1")
                                            .arg(mFileInfo.baseName()));
    }
    STATUS(mStatus);
    emit status(mStatus);
    return isError();
}

void XmlDocObject::finish()
{
    FNENTER();
    DUMPQSL(toDebugStrings());
    emit finished();
}

void XmlDocObject::startParse()
{
    FNENTER();
    mDocument.setContent(mBytes);
    if ( ! mDocument.isDocument())
    {
        mStatus.set(StatusLevel::WExpect,
                    QString("Unable to load XML Document from %1")
                        .arg(mFileInfo.toString()));
        STATUS(mStatus);
    }
    else
    {
        mRootElement = mDocument.documentElement();
        if (mRootElement.isElement())
        {
            KeyElement rootKE(Key("/"), mRootElement);
            mPendingKeyElements.enqueue(rootKE);
        }
        QTimer::singleShot(10, &XmlDocObject::parseNext);
    }
}

void XmlDocObject::parseNext()
{
    FNENTER();
    if (mPendingKeyElements.isEmpty())
    {

        QTimer::singleShot(10, &XmlDocObject::finish);
    }
    else
    {
        const KeyElement tKE = mPendingKeyElements.dequeue();
        const Key cKey = tKE.first;
        const QDomElement cDE = tKE.second;
        mCurrentGroupKey.append(cKey);
        QDomNamedNodeMap tDNNMap = cDE.attributes();
        parseAttributes(tDNNMap);
        mKeyMap.insert(mCurrentGroupKey, cDE.text());
        for(QDomNode tNode = cDE.firstChild();
             ! tNode.isNull();
             tNode = tNode.nextSibling())
            if (tNode.isElement())
            {
                KeyElement tKE;
                tKE.first = mCurrentGroupKey + tNode.nodeName();
                tKE.second = tNode.toElement();
                mPendingKeyElements.enqueue(tKE);
            }
    }
}

void XmlDocObject::parseAttributes(const QDomNamedNodeMap &aDNNMap)
{
    for (Index ix = 0; ix < aDNNMap.length(); ++ix)
    {
        const QDomNode cNode = aDNNMap.item(ix);
        const QString cName = cNode.nodeName();
        const QString cText = cNode.nodeValue();
        mKeyMap.insert(mCurrentGroupKey + KeySeg(cName), cText);
    }
}

KeyTextMap XmlDocObject::map(const Key &aGroupKey) const
{
    KeyTextMap result = mKeyMap;
    result = result.extract(aGroupKey);
    return result;
}

QStringList XmlDocObject::toDebugStrings()
{
    QStringList result;
    result << QString("XmlDocObject:    %1").arg(fileInfo().completeBaseName());
    result << QString("Status:          %1").arg(status().toString());
    result << QString("FileInfo:        %1").arg(fileInfo().toString());
    result << QString("FileInfo:        %1").arg(fileInfo().toString());
    result << QString("KeyTextMap:      %1 entries").arg(map().count());
    result << map().toDebugStrings();
    return result;
}
