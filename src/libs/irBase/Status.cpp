#include "Status.h"

Status::Status(const StatusLevel aLevel) : mLevel(aLevel) {;}
Status::Status(const StatusLevel aLevel, const AText &aMsg) : mLevel(aLevel), mMessage(aMsg) {;}

QString Status::toString() const
{
    return QString("%1: %2")
        .arg(level().name()(), 16, level().prefix())
        .arg(message()());
}

void Status::set(const StatusLevel aLevel, const AText &aMsg)
{
    level(aLevel), message(aMsg);
}

