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

void Status::set(const StatusLevel aLevel, const AText &aFmt,
                 const QVariantList &aVars)
{
    const AText cText = AText::formatted(aFmt, aVars);
    set(aLevel, cText);
}

void Status::set(const StatusLevel aLevel, const AText &aFmt,
                 const QVariant &aVar1, const QVariant &aVar2,
                 const QVariant &aVar3, const QVariant &aVar4)
{
    QVariantList tQVL;
    tQVL << aVar1;
    if (aVar2.isValid())    tQVL << aVar2;
    if (aVar3.isValid())    tQVL << aVar3;
    if (aVar2.isValid())    tQVL << aVar4;
    set(aLevel, aFmt, tQVL);
}


