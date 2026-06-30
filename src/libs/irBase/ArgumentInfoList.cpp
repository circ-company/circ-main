#include "ArgumentInfoList.h"

QVariantList ArgumentInfoList::values() const
{
    QVariantList result;
    foreach (const ArgumentInfo cInfo, it())
        result << cInfo.value();
    return result;
}
