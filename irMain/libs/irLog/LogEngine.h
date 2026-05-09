#pragma once

#include <QObject>

#include <QStringList>

class LogEngine : public QObject
{
    Q_OBJECT

public: // tyoes
    static const QStringList scmMessageFields;

public: // ctors
    explicit LogEngine(QObject *parent = nullptr);

signals:
};
