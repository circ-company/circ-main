#include "LogEngine.h"


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

LogEngine::LogEngine(QObject *parent) : QObject{parent} {;}


