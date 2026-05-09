#include "LogItem.h"

#include <MillisecondTime.h>

DEFINE_DATAPROPS(LogItem, LogItemData)

void LogItem::ctor(void)
{
    TimeStamp(MillisecondTime::current()());
}

void LogItem::dtor(void) {}
