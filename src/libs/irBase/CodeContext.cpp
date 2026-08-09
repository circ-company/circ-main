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
}

bool CodeContext::isSameFunction(const CodeContext &other) const
{
    return fileName() == other.fileName() && qfiText() == other.qfiText();
}

FSText CodeContext::baseFileName() const
{
    FSText result;
    if (mFileInfo.exists())
        result = mFileInfo.completeBaseName();
    return result;
}

FSText CodeContext::lineTime() const
{
    FSText result;
    result.append(QString("%1 %2")
              .arg(fileLine())
                      .arg(MillisecondTime(mEpochMS).timeString(true)));
    return result;
}

AText CodeContext::toString() const
{
    AText result;
    if ( ! isNull())
        result.append(AText(QString("{%1(%2) %3}")
            .arg(baseFileName()()
                , fileLine() ? QString::number(fileLine()) : QString()
                , qfiText()())));
    return result;
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
    return QString(timeFirst
                  ? "{@%1: {%2(%3) %4 in %5}"
                  : "{%2(%3) %4 @%1 in %5}")
              .arg(MillisecondTime(mEpochMS).timeString(true)   // %1
                   , mFileInfo.completeBaseName())              // %2
              .arg(mFileLine, 4, 10, u'0')                      // %3
              .arg(mQFIText()                                   // %4
                   , mFileInfo.dir().path());                   // %5
}

QStringList CodeContext::toDebugStrings() const
{
    QStringList result;
    result << QString("{==Code Context:           %1")
                  .arg(MillisecondTime(mEpochMS).timeString(true));
    result << QString("---File:                   %1.%2(%3)")
                  .arg(mFileInfo.completeBaseName()
                       , mFileInfo.completeSuffix())
                  .arg(mFileLine);
    result << QString("---Directory:              %1")
                  .arg(mFileInfo.dirLast()());
    result << QString("   At:                     %1")
                  .arg(mFileInfo.dirFirst(-1, '/')());

    return result;

}
