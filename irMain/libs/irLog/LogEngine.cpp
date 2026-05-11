#include "LogEngine.h"

#include <MillisecondTime.h>


LogEngine::LogEngine(QObject *parent) : QObject{parent} {;}

/* --------------------- static public --------------------- */

QString LogEngine::messagePattern()
{
    QString result = "LogEngine::messageFormat(){";
    QStringList tEntryList;
    tEntryList << "EpochMsec=" + QString::number(MillisecondTime::current()());
    foreach (const QString cField, scmMessageFields)
    {
        QString tEntry = cField + "=%{" + cField.toLower() + "}";
        tEntryList << tEntry;
    }
    result += tEntryList.join('^');
    result += "}";
    return result;
}


/* --------------------- static private --------------------- */

const QStringList scmMessageFields = QStringList()
                                     << "AppName"
                                     << "Category"
                                     << "File"
                                     << "Line"
                                     << "Function"
                                     << "PID"
                                     << "ThreadName"
                                     << "Type"
                                     << "Backtrace";
