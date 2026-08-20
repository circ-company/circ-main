#pragma once

#include <QObject>

class MessageCenter : public QObject
{
    Q_OBJECT
public:
    explicit MessageCenter(QObject *parent = nullptr);

signals:
};
