#include "CodeContext.h"

#include <QtDebug>
#include <QDir>

#include "MillisecondTime.h"

CodeContext::CodeContext(const QString &qfi, const FSText &file, const int line)
    : mEpochMS(MillisecondTime::current())
    , mQFIText(qfi)
    , mFileName(file)
    , mFileLine(line)
    , mFuncInfo(mQFIText)
    , mFileInfo(mFileName)
{
//    qInfo() << Q_FUNC_INFO << qfi << file << line << mFuncInfo.toDebugString() << mFileInfo;
}

FSText CodeContext::baseFileName() const
{
    FSText result;
    if (mFileInfo.exists())
        result = mFileInfo.completeBaseName();
    return result;
}

AText CodeContext::toString() const
{
    AText result('{');
    result.append(QString("%1(%2) %3")
                       .arg(baseFileName()())
                       .arg(fileLine(), 4, 10, u'0')
                       .arg(qfiText()()));
    return result + AText('}');
}

void CodeContext::clear()
{
    mEpochMS = 0;
    mQFIText.clear();
    mFileName.clear();
    mFileLine = 0;
    mFuncInfo.clear();
    mFileInfo.clear();
}

QString CodeContext::toDebugString(const bool timeFirst) const
{
    return timeFirst
      ? QString("{@%1: {%2(%3) %4 in %5}")
              .arg(MillisecondTime(mEpochMS).timeString(true))
              .arg(mFileInfo.completeBaseName())
              .arg(mFileLine, 4, 10, u'0')
              .arg(mQFIText())
              .arg(mFileInfo.dir().path())
      : QString("{%1(%2) %3 @%4 in %5}")
                .arg(mFileInfo.completeBaseName())
                .arg(mFileLine, 4, 10, u'0')
                .arg(mQFIText())
                .arg(MillisecondTime(mEpochMS).timeString(true))
                .arg(mFileInfo.dir().path());
}

QStringList CodeContext::toDebugStrings() const
{
    QStringList result;
    result << QString("{==Code Context:           %1")
                  .arg(MillisecondTime(mEpochMS).timeString(true));
    result << QString("---File:                   %1.%2(%3)")
                  .arg(mFileInfo.completeBaseName())
                  .arg(mFileInfo.completeSuffix())
                  .arg(mFileLine);
    result << QString("---Directory:              %1")
                  .arg(mFileInfo.dirLast()());
    result << QString("   At:                     %1")
                  .arg(mFileInfo.dirFirst(-1, '/')());

    return result;

}
