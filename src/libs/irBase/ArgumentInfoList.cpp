#include "ArgumentInfoList.h"

/*
Count ArgumentInfoList::count() const
{
    return 0;
}
*/
QVariantList ArgumentInfoList::values() const
{
    QVariantList result;
    foreach (const ArgumentInfo cInfo, it())
        result << cInfo.value();
    return result;
}
/*
void ArgumentInfoList::set(const Index ix, const ArgumentInfo &aInfo)
{
    Q_UNUSED(ix); Q_UNUSED(aInfo);
}
*/
