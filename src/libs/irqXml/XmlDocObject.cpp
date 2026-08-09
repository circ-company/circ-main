#include "XmlDocObject.h"

#include <QDomAttr>
#include <QDomNamedNodeMap>
#include <QDomNode>
#include <QTimer>

#include <FileInfo.h>
#include <Log.h>

#include "DocParseResult.h"

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
    connect(this, &XmlDocObject::dataRead,
            this, &XmlDocObject::setDocument);
    connect(this, &XmlDocObject::docSet,
            this, &XmlDocObject::startRoot);
    connect(this, &XmlDocObject::parseFinished,
            this, &XmlDocObject::finish);
}

void XmlDocObject::clear()
{
    mStatus.clear();
    mFileInfo.nullify();
    mBytes.clear();
    mDocument.clear();
    mRootElement.clear();
    mKeyMap.clear();
    emit cleared();
    emit level(mStatus.level());
    emit status(mStatus);
}

void XmlDocObject::set(const FileInfo &aFileInfo)
{
    mFileInfo = aFileInfo;
    if ( ! mFileInfo.exists()
            || ! mFileInfo.isReadable()
            || ! mFileInfo.isFile())
    {
        mStatus.set(StatusLevel::Error, QString("Expected "
                        "existing readable file: %1 in $2")
                        .arg(mFileInfo.baseName())
                        .arg(mFileInfo.toString(FileInfo::ElipsesPath)));
        emit level(mStatus.level());
        emit error(mStatus.level());
    }
    else
    {
        emit fileSet(mFileInfo);
        mStatus.note(AText::format("XmlDocObject::set(%1) in %2",
                     mFileInfo.baseName(),
                     mFileInfo.toString(FileInfo::ElipsesPath)));
    }
    emit status(mStatus);
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
    EXPECTNOT(mFileInfo.isNull());
    QFile * pFile = new QFile(this);
    NEWOBJ(pFile, QFile, this);
    if (pFile)
    {
        pFile->setFileName(mFileInfo.filePath());
        bool ok = pFile->open(QIODevice::ReadOnly
                             | QIODevice::ExistingOnly
                             | QIODevice::Text);
        mStatus.set(pFile);
        if (ok)
        {
            mBytes = pFile->readAll().mid(3);
            const QByteArrayList cQBAL = mBytes.split('\n');
            DUMPQBAL(cQBAL);
            FNEMITARG("fileRead", mFileInfo, "FileInfo");
            emit fileRead(mFileInfo);
            WEXPECTEQ(pFile->size() - 3, mBytes.length());
            FNEMITARG("dataRead", mBytes, "QByteArray");
            emit dataRead(mBytes);
            mStatus.note(AText::format("Opened File: %1", pFile->fileName()));
        }
        else
        {
            emit level(mStatus.level());
            emit error(mStatus.level());
            WASSERT(ok);
        }
        pFile->close();
        pFile->deleteLater();
    }
    else
    {
        mStatus.set(StatusLevel::Error, QString("Unable to create file object: %1")
                                            .arg(mFileInfo.baseName()));
    }
    STATUS(mStatus);
    FNEMITARG("status", mStatus, "Status");
    emit status(mStatus);
    bool result = isError();
    FNRTNVALUE(result, "bool");
    return result;
}

bool XmlDocObject::setDocument()
{
    FNENTER();
    bool result = false;
    DocParseResult parseResult(mDocument.setContent(mBytes));
    if (bool(parseResult))
    {
        result = true;
        FNEMITARG("docSet", mDocument.toByteArray(2), "QByteArray");
        emit docSet(mDocument.toByteArray(2));
    }
    else
    {
        DUMPVAR(parseResult.toString());
        FNEMITARG("docSetError", parseResult.toString(), "QString");
        emit docSetError(parseResult);
    }
    FNRTNVALUE(bool(parseResult), "bool");
    return result;
}

void XmlDocObject::finish()
{
    FNENTER();
    DUMPQSL(toDebugStrings());
    mStatus.note("Parsing finished");
    STATUS(mStatus);
    FNEMIT(finished);
    emit finished();
    FNRTNVOID();
}

// private slot
void XmlDocObject::startRoot()
{
    FNENTER();
    mRootElement = mDocument.documentElement();
    EXPECTIS(mRootElement.isElement());
    mStatus.note("Root element set");
    for (QDomElement tDE = mRootElement.firstChildElement();
         ! tDE.isNull();
         tDE = tDE.nextSiblingElement())
    {
        parse(tDE.tagName(), tDE);
    }
    FNEMIT(parseFinished);
    emit parseFinished();
    FNRTNVOID();
}

void XmlDocObject::parse(const Key &aKey, const QDomElement &aDE)
{
    FNENTER();
    EXPECTIS(aDE.isElement());
    FNARG(aKey(), Key);
    FNARG(aDE.tagName(), QString);
    FNARG(aDE.text(), QString);
    Key tBaseKey = aKey;
    if (tBaseKey.last() != KeySeg(aDE.tagName()))
        tBaseKey.append(KeySeg(aDE.text()));
    QDomNamedNodeMap tQDNNMap = aDE.attributes();
    const Count cQDNNMapCount = tQDNNMap.count();
    for (Index ix = 0; ix < Index(cQDNNMapCount); ++ix)
    {
        const QDomNode cNode = tQDNNMap.item(ix);
        EXPECTIS(cNode.isAttr());
        const QDomAttr cAttr = cNode.toAttr();
        const QString cName = cAttr.name();
        const QString cValue = cAttr.value();
        insert(tBaseKey + KeySeg(cName), cValue);
    }
    const QString cText = aDE.text();
    if ( ! cText.isEmpty())
        insert(tBaseKey + KeySeg("[TEXT]"), cText);
    QDomElement tSubDE = aDE.firstChildElement();
    while ( ! tSubDE.isNull())
    {
        EXPECTIS(tSubDE.isElement());
        parse(tBaseKey + KeySeg(tSubDE.tagName()), tSubDE); // re-entrant!
        tSubDE = tSubDE.nextSiblingElement();
    }
    FNRTNVOID();
}
#if 0
// private slot
void XmlDocObject::parseNext()
{
    FNENTER();
    if (mPendingKeyElements.isEmpty())
    {
        emit parseFinished();
        QTimer::singleShot(10, &XmlDocObject::finish);
    }
    else
    {
        const KeyElement tKE = mPendingKeyElements.dequeue();
        const Key cKey = tKE.first;
        const QDomElement cDE = tKE.second;
        INFOMSG(AText::format("Parsing Group=%1 Key=%2 DE=%3",
                              mCurrentGroupKey(),
                              tKE.first(), tKE.second.tagName()));
        mCurrentGroupKey.append(cKey);
        QDomNamedNodeMap tDNNMap = cDE.attributes();
        parseAttributes(tDNNMap);
        const QString cDEText = cDE.text();
        if ( ! cDEText.isEmpty())
            mKeyMap.insert(mCurrentGroupKey + "[TEXT]", cDEText);
        for(QDomNode tNode = cDE.firstChild();
             ! tNode.isNull();
             tNode = tNode.nextSibling())
            if (tNode.isElement())
            {
                KeyElement tKE;
                tKE.first = mCurrentGroupKey + tNode.nodeName();
                tKE.second = tNode.toElement();
                INFOMSG(AText::format("Queuing Group=%1 Key=%2 DE=%3",
                                      mCurrentGroupKey(),
                                      tKE.first(), tKE.second.tagName()));
                mPendingKeyElements.enqueue(tKE);
            }
        FNEMITARG("parsedElement", cDE.tagName(), "QString");
        emit parsedElement(cDE);
    }
    FNRTNVOID();
}
#endif
#if 0
// private slot
void XmlDocObject::parseAttributes(const QDomNamedNodeMap &aDNNMap,
                                   const bool aTrace)
{
    Q_UNUSED(aTrace)
    // FNARG(aDNNMap.length(), Count);
    for (Index ix = 0; ix < aDNNMap.length(); ++ix)
    {
        const QDomNode cNode = aDNNMap.item(ix);
        const QString cName = cNode.nodeName();
        const QString cText = cNode.nodeValue();
        mKeyMap.insert(mCurrentGroupKey + KeySeg(cName), cText);
        INFOMSG(AText::format(
                        "Insert: Group=%1 Key=%2 Text=%3",
                        mCurrentGroupKey(), cName, cText));
    }
    // FNRTNVOID();
}
#endif
void XmlDocObject::insert(const Key &aKey, const QString &aValue)
{
    INFOMSG(AText::format("Inserting: Key=%1 Value=<%2>",
            aKey(), aValue));
    mKeyMap.insert(aKey, aValue);
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
    result << QString("KeyTextMap:      %1 entries").arg(map().count());
    result << map().toDebugStrings();
    return result;
}
