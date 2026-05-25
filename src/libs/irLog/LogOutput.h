#pragma once

#include <QObject>

class LogOutputBehavoir;

class LogOutput : public QObject
{
    Q_OBJECT
protected:
    explicit LogOutput(QObject *parent = nullptr);

public slots:

signals:

private:
};
