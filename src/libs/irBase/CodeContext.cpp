#include "CodeContext.h"

#include <QtDebug>
#include <QDir>

#include "NanosecondTime.h"

CodeContext::CodeContext(const QString &qfi, const FSText &file, const int line)
    : mQFIText(qfi)
    , mFileName(file)
    , mFileLine(line)
    , mFuncInfo(mQFIText)
    , mFileInfo(mFileName)
{
//    qInfo() << Q_FUNC_INFO << qfi << file << line << mFuncInfo.toDebugString() << mFileInfo;
}

AText CodeContext::toString(const bool withTime) const
{
    AText result = QString("%1(%2) %3 ")
                       .arg(fileName()(), -20)
                       .arg(fileLine(), -4, 10, u'0')
                       .arg(qfiText()());
    if (withTime) result += NSTime().timeString();
    return result;
}

void CodeContext::clear()
{
    mEpochNS = 0;
    mQFIText.clear();
    mFileName.clear();
    mFileLine = 0;
    mFuncInfo.clear();
    mFileInfo.clear();
}

QString CodeContext::toDebugString(const bool timeFirst) const
{
    const NanosecondTime cNST(mEpochNS);
    return timeFirst
      ? QString("{@%1 %2(%3) %4 in %5}")
              .arg(cNST.timeString())
              .arg(mFileInfo.completeBaseName())
              .arg(mFileLine, 4, 10, u'0')
              .arg(mQFIText())
              .arg(mFileInfo.dir().path())
      : QString("{%1(%2) %3 @%4 in %5}")
                .arg(mFileInfo.completeBaseName())
                .arg(mFileLine, 4, 10, u'0')
                .arg(mQFIText())
                .arg(NanosecondTime(mEpochNS).timeString())
                .arg(mFileInfo.dir().path());
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
