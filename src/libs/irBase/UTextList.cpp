#include "UTextList.h"

UTextList::UTextList(const QStringList &qsl) { set(qsl); }

bool UTextList::isValidIndex(const Index ix) const
{
    return ix >= 0 && ix < count();
}

void UTextList::set(const QStringList &qsl)
{
    clear();
    foreach (const QString cQS, qsl)
        append(UText(cQS));
}
