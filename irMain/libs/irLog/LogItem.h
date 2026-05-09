#pragma once

#include <QSharedDataPointer>
#include <DataProperty.h>

#include <QFileInfo>
#include <QString>

#include "Types.h"

#define LOGITEM_DATAPROPS(TND) \
    TND(Milliseconds, TimeStamp, 0) \
    TND(int, Severity, 0) \
    TND(QString, Appname, QString()) \
    TND(QString, Category, QString()) \
    TND(QFileInfo, File, QFileInfo()) \
    TND(QString, Function, QString()) \
    TND(int, Line, 0) \
    TND(qint64, PID, 0) \
    TND(QString, Threadname, QString()) \
    TND(QString, Type, QString()) \
    TND(QStringList, Backtrace, QStringList()) \

class LogItemData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(LOGITEM_DATAPROPS);
public:
    LogItemData(void)
    {
        DEFINE_DATAPROPS_CTORS(LOGITEM_DATAPROPS);
    }
};

class LogItem
{
    DECLARE_PARENT_DATAPROPS(LOGITEM_DATAPROPS)
    DECLARE_DATAPROPS(LogItem, LogItemData)
};
