#include "Status.h"

#include <QFile>

#include "FileInfo.h"
#include "MillisecondTime.h"

Status::Status(const StatusLevel aLevel) : mLevel(aLevel) {;}
Status::Status(const StatusLevel aLevel, const AText &aMsg)
    : mLevel(aLevel), mMessage(MillisecondTime::current(), aMsg) {;}

AText Status::timetext() const
{
    return AText(toString());
}

ATextList Status::notes() const
{
    ATextList result;
    foreach (const TimeText cTT, mNotes)
    {
        const MillisecondTime cMST(cTT.first);
        const AText cText = cTT.second;
        result << AText(QString("%1: %2")
                            .arg(cMST.timeString(true))
                            .arg(cText()));
    }
    return result;
}

QString Status::toString() const
{
    return QString("%3%1: %2")
        .arg(level().name()(), 16, level().prefix())
        .arg(message()())
        .arg(MillisecondTime(mMessage.first).timeString(true));
}

QStringList Status::toStrings() const
{
    QStringList result;
    result << toString();
    result << notes().toStringList();
    return result;
}

void Status::clear()
{
    mLevel = StatusLevel::$null;
    mMessage.first = 0;
    mMessage.second.clear();
    mNotes.clear();
}

void Status::set(const StatusLevel aLevel, const AText &aMsg)
{
    level(aLevel), message(aMsg);
}

void Status::set(const StatusLevel aLevel, QFile *pFile)
{
    QString tMsg = QString("File Error: %1(%2) in %3")
                       .arg(pFile->errorString()).arg(pFile->error())
                       .arg(FileInfo(pFile->fileName())
                                .toString(FileInfo::ElipsesPath
                                          | FileInfo::FileName
                                          | FileInfo::Status
                                          | FileInfo::Characteristics));
    set(aLevel, AText(tMsg));
}


void Status::message(const AText &aMsg)
{
    mMessage.first = MillisecondTime::current();
    mMessage.second = aMsg;
}

