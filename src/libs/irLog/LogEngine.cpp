#include "LogEngine.h"

#include <QTextStream>

#include <ATextList.h>

#include "LogMsgType.h"

LogEngine::LogEngine()
    : QObject{nullptr}
{
    (void)StatusLevel::instance();
}

void LogEngine::initialize()
{
}

void LogEngine::capture()
{
#if 0
    qSetMessagePattern(messagePattern());
    mpOldHandler = qInstallMessageHandler(&messageHandler);
    mCaptured = mpOldHandler;
    emit captured();
#endif
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
    const Uid cUid = li.uid();
    const StatusLevel cLevel = li.level();
    mUidItemMap.insert(cUid, li);
    mLevelUidMMap.insert(cLevel, cUid);
    if ( ! mCaptured && mTrollEnabled) sendTroll(li);
}

void LogEngine::dequeue()
{

}

void LogEngine::flush()
{
    QFile * pFile = new QFile(this);
    Q_ASSERT(pFile);
    if (pFile->open(stderr, QIODevice::WriteOnly))
    {
        pFile->flush();
        pFile->close();
    }
    if (pFile->open(stdout, QIODevice::WriteOnly))
    {
        pFile->flush();
        pFile->close();
    }
    pFile->deleteLater();
}

bool LogEngine::isEmpty() const
{
    Q_ASSERT(mUidItemMap.count() == mLevelUidMMap.count());
    return mUidItemMap.isEmpty();
}

LogItem LogEngine::takeQueue()
{
    LogItem result(LogItem::Type::$nullType, StatusLevel(), CodeContext());
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
    static CodeContext stCurrentContext;
    const CodeContext cThisContext = li.context();
    MillisecondTime tMST(li.ems());
    const StatusLevel cLevel = li.level();
#if 1 //def __LOG_SUPRESS_OK
    if (StatusLevel::TOK == cLevel) return;                     /*/=====\*/
#endif
    const int cLevelValue = cLevel.value();
    const QString cLevelString = cLevel.string(12);
    const LogMsgType cLMT = LogMsgType::from(cLevel);
    const char cLmtChar = cLMT.prefix();
    const AText cMsgAtx = li.formatted();
    if ( ! cThisContext.isNull()
            && ! stCurrentContext.isSameFunction(li.context()))
    {
        QString tContext = QString("%4 %1 [%2 %3]\n")
            .arg(cThisContext.funcInfo().completeBaseName()()
                ,cThisContext.baseFileName()()
                ,cThisContext.fileInfo().toString(FileInfo::ElipsesPath)
                ,AText(cThisContext.functionLevel(), "-->")());
        writeTroll(cLMT, tContext);
        stCurrentContext = cThisContext;
    }
    QString tText = QString("%1[%2] %3(%4): [%5]\n")
                        .arg(tMST.timeString(true))                 // %1
                        .arg(cThisContext.fileLine(), 4, 10, u'0')  // %2
                        .arg(cLevelString, 12, cLmtChar)            // %3
                        .arg(cLevelValue)                           // %4
                        .arg(cMsgAtx());                            // %5
    writeTroll(cLMT, tText);
}

void LogEngine::writeTroll(const LogMsgType lmt, const QString msg)
{
    switch (lmt.qmt())
    {
    case QtInfoMsg:         qInfo() << msg;       break;
    case QtDebugMsg:        qDebug() << msg;      break;
    default:                Q_FALLTHROUGH();
    case QtWarningMsg:      qWarning() << msg;    break;
    case QtFatalMsg:        Q_FALLTHROUGH(); // let LogEngine::enqueue'r fault
    case QtCriticalMsg:     qCritical() << msg;   break;
    }
}

/* --------------------- static public --------------------- */

#if 0
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
#endif

