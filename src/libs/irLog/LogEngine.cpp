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

void LogEngine::enqueue(LogItem li)
{
    //Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    const Type cType = li.type();
    const Uid cUid = li.uid();
    const Severity cSev = li.severity();
    switch (cType)
    {
    case Type::Formatted:   li.set(li.formatted());     break; // new message
    default:                /* leave alone */           break; // TODO more?
    }

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
    LogItem result(LogItem::Type::$null, Severity(), CodeContext());
    Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    if ( ! isEmpty())
    {
        const Severity cSev = mSevUidMMap.lastKey();
        const Uid cUid = mSevUidMMap.last();
        Q_ASSERT(mUidItemMap.contains(cUid));
        LogItem tItem = mUidItemMap.take(cUid);
        if ( ! tItem.isNull())
            result = tItem;
        mSevUidMMap.remove(cSev, cUid);
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
    const NanosecondTime cNST = li.context().NSTime();
    QString tText = QString("%1%2: <%3> %4\n")
                        .arg(cNST.timeString())
                        .arg(cSev.name()(), -10, cLMT.prefix())
                        .arg(li.message()())
                        .arg(li.contextString()());
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
