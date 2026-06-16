#include "NameFilters.h"

void NameFilters::setExtensions(const QString &exts)
{
    QStringList extList = exts.simplified().split(' ');
    foreach (QString cExt, extList)
        mFilterList.append("*." + cExt),
            mFilterList.append("*." + cExt.toLower());
}
