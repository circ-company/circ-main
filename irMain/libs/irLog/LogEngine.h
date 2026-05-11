#pragma once

#include <QObject>

#include <QStringList>

class LogEngine : public QObject
{
    Q_OBJECT


public: // tyoes
    explicit LogEngine(QObject *parent = nullptr);

public slots:
    void install();
    void remove();

signals:
    void installed();
    void removed();

public: // const

public: // non-const

public: // static
    static QString messagePattern();

private: // static
    static const QStringList scmMessageFields;

};
