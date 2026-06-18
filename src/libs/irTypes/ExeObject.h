#pragma once

#include <QObject>

class ExeObject : public QObject
{
    Q_OBJECT
public:
    explicit ExeObject(QObject *parent = nullptr);

signals:
};
