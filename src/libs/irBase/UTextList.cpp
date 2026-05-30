#include "UTextList.h"

UTextList::UTextList(const QStringList &qsl) { set(qsl); }

void UTextList::set(const QStringList &qsl)
{
    clear();
    foreach (const QString cQS, qsl)
        append(UText(cQS));
}
