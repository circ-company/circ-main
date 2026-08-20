#pragma once

#include <QObject>

class Messenger : public QObject
{
    Q_OBJECT
public: // ctors
    explicit Messenger(QObject *parent = nullptr);

signals:
};
