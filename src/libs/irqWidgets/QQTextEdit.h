#pragma once

#include <QTextEdit>

class QQTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    QQTextEdit(QObject *parent = nullptr);
};
