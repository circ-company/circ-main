#include "LogEngine.h"

#include <QTextStream>

#include <ATextList.h>
#include <NanosecondTime.h>

#include "LogMsgType.h"

LogEngine::LogEngine() : QObject{nullptr} {;}

void LogEngine::capture()
{
    qSetMessagePattern(messagePattern());
    mpOldHandler = qInstallMessageHandler(&messageHandler);
    mCaptured = mpOldHandler;
    emit captured();
}

void LogEngine::release()
{
    qSetMessagePattern("%{if-category}%{category}: %{endif}%{message}");
    if (mpOldHandler)
        qInstallMessageHandler(mpOldHandler);
    mpOldHandler = nullptr;
    mCaptured = mpOldHandler;
    emit released();
}

void LogEngine::enqueue(const LogItem &li)
{
    //Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    const Uid cUid = li.uid();
    const Severity cSev = li.severity();
    mUidItemMap.insert(cUid, li);
    mSevUidMMap.insert(cSev, cUid);
    //Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    if ( ! mCaptured && mTrollEnabled) sendTroll(li);
}

void LogEngine::dequeue()
{

}

bool LogEngine::isEmpty() const
{
    Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    return mUidItemMap.isEmpty();
}

LogItem LogEngine::takeQueue()
{
    LogItem result;
    Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    if ( ! isEmpty())
    {
        Severity tSev = mSevUidMMap.lastKey();
        Uid tUid = mSevUidMMap.last();
        Q_ASSERT(mUidItemMap.contains(tUid));
        LogItem tItem = mUidItemMap.take(tUid);
        if ( ! tItem.isNull())
            result = tItem;
        mSevUidMMap.remove(tSev, tUid);
        Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    }
    if (isEmpty())
        emit empty();
    else
        emit count(mUidItemMap.count());
    return result;
}

void LogEngine::sendTroll(const LogItem &li)
{
    const Severity cSev = li.severity();
    const LogMsgType cLMT = LogMsgType::from(cSev);
    const Uid cUid = li.uid();
    const NanosecondTime cNST(cUid.nsecs());
    QString tText = QString("%1%2 <%3> %4")
                        .arg(cLMT.prefix(), cNST.timeString(),
                         li.formatted()(), li.contextString()());
    writeTroll(cLMT, tText);
}

void LogEngine::writeTroll(const LogMsgType lmt, const AText atx)
{
    switch (lmt.qmt())
    {
    case QtInfoMsg:         qInfo() << atx();       break;
    case QtDebugMsg:        qDebug() << atx();      break;
    case QtWarningMsg:      qWarning() << atx();    break;
    default:
    case QtCriticalMsg:     qCritical() << atx();   break;
    case QtFatalMsg:        qFatal() << atx();      break;
    }
}

/* --------------------- static public --------------------- */

KeyTextMap LogEngine::parse(const QString s)
{
    KeyTextMap result;
    foreach (const AText cAtx, AText(s).split('^'))
    {
        Index ix = cAtx.indexOf('=');
        if (ix < 0) continue;                               /*^^^^^^*/
        const Key cKey(AText(cAtx.left(ix)));
        const CText cValue = cAtx.mid(ix);
        const Key cPrefix = (scmMessageFields.contains(cKey)) ? "Message" : "Other";
        result.set(cKey, cValue);
    }
    return result;
}

QString LogEngine::messagePattern()
{
    QString result = "LogEngine::messageFormat(){";
    QStringList tEntryList;
    foreach (const QString cField, scmMessageFields)
    {
        QString tEntry = cField + "=%{" + cField.toLower() + "}";
        tEntryList << tEntry;
    }
    result += tEntryList.join('^');
    result += "}";
    return result;
}

/* --------------------- static private --------------------- */

void LogEngine::messageHandler(QtMsgType qmt, const QMessageLogContext &qmlctx, const QString &s)
{
    const LogMsgType cLMT(qmt);
    const Severity cSev(qmt);
    const CodeContext cCtx(qmlctx.function, qmlctx.file, qmlctx.line);
    LogItem li(Log::Troll, cSev, cCtx);
    li.set(AText(s));
    LOG->enqueue(li);
}

const QStringList LogEngine::scmMessageFields = QStringList()
                                     << "Message"
                                     << "AppName"
                                     << "Category"
                                     << "File"
                                     << "Line"
                                     << "Function"
                                     << "PID"
                                     << "ThreadName"
                                     << "Type"
                                     << "Backtrace";
