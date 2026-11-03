#pragma once

#include <QObject>

class boostLogFunction : public QObject
{
    Q_OBJECT
public:
    explicit boostLogFunction(QObject*parent =nullptr);
    boostLogFunction(const char * aQFI, const char * aFile,
                     const int aLine, QObject*parent =nullptr);


signals:
};
