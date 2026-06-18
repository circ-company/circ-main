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
    const StatusLevel cLevel = li.level();
    switch (cType)
    {
    case Type::MessageOnly: break;
    case Type::Formatted:   li.set(li.formatted());     break; // new message
    default:        //        /* leave alone */           break; // TODO more?
        qWarning() << Q_FUNC_INFO << "Unhandled Type:"
                   << cType << cLevel.name();
        break;
    }

    mUidItemMap.insert(cUid, li);
    mLevelUidMMap.insert(cLevel, cUid);
    //Q_ASSERT(mUidItemMap.count() == mSevUidMMap.count());
    if ( ! mCaptured && mTrollEnabled) sendTroll(li);
}

void LogEngine::dequeue()
{

}

bool LogEngine::isEmpty() const
{
    Q_ASSERT(mUidItemMap.count() == mLevelUidMMap.count());
    return mUidItemMap.isEmpty();
}

LogItem LogEngine::takeQueue()
{
    LogItem result(LogItem::Type::$null, StatusLevel(), CodeContext());
    Q_ASSERT(mUidItemMap.count() == mLevelUidMMap.count());
    if ( ! isEmpty())
    {
        const StatusLevel cSlv = mLevelUidMMap.lastKey();
        const Uid cUid = mLevelUidMMap.last();
        Q_ASSERT(mUidItemMap.contains(cUid));
        LogItem tItem = mUidItemMap.take(cUid);
        if ( ! tItem.isNull())
            result = tItem;
        mLevelUidMMap.remove(cSlv, cUid);
        Q_ASSERT(mUidItemMap.count() == mLevelUidMMap.count());
    }
    if (isEmpty())
        emit empty();
    else
        emit count(mUidItemMap.count());
    return result;
}

void LogEngine::sendTroll(const LogItem &li)
{
    const StatusLevel cLevel = li.level();
    const int cLevelValue = cLevel.value();
    const CText cLevelName = cLevel.name();
    const LogMsgType cLMT = LogMsgType::from(cLevel);
    const char cLmtChar = cLMT.prefix();
    const AText cMsgAtx = li.message();
    const AText cCtxAtx = li.context().toString(false);
    const NanosecondTime cNST = li.context().NSTime();
    const QString cNstStr = cNST.timeString();
    QString tText = QString("%1 %2(%5): <%3> %4\n")
                        .arg(cNstStr)
                        .arg(cLevelName(), -10, cLmtChar)
                        .arg(cMsgAtx())
                        .arg(cCtxAtx())
                        .arg(cLevelValue)
        ;
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
    const StatusLevel cSlv(qmt);
    const CodeContext cCtx(qmlctx.function, qmlctx.file, qmlctx.line);
    LogItem li(Log::Troll, cSlv, cCtx);
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
