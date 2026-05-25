#include "CodeContext.h"

#include <QtDebug>

#include "NanosecondTime.h"

CodeContext::CodeContext(const QString &qfi, const FSText &file, const int line)
    : mQFIText(qfi)
    , mFileName(file)
    , mFileLine(line)
    , mFuncInfo(mQFIText)
    , mFileInfo(mFileName)
{
    qInfo() << Q_FUNC_INFO << qfi << file << line << mFuncInfo.toDebugString() << mFileInfo;
}

QString CodeContext::toDebugString() const
{
    return QString("{%1(%2) %3 @%4}")
        .arg(mFileInfo.completeBaseName())
        .arg(mFileLine)
        .arg(mQFIText())
        .arg(NanosecondTime(mEpochNS).timeString());
}

QStringList CodeContext::toDebugStrings() const
{
    QStringList result;
    result << QString("{==Code Context:           %1")
                  .arg(NanosecondTime(mEpochNS).timeString());
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
