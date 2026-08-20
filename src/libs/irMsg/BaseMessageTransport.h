#pragma once

#include <QObject>

class BaseMessageTransport : public QObject
{
    Q_OBJECT
public:
    explicit BaseMessageTransport(QObject *parent = nullptr);

signals:
};
