#pragma once

#include <QTextDocument>

class QQTextDocument : public QTextDocument
{
    Q_OBJECT
public:
    explicit QQTextDocument(QObject *parent = nullptr);
};
