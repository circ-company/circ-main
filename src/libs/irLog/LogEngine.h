#pragma once

#include <QObject>

#include <QQueue>
#include <QStringList>

#include <LogItem.h>
#include <Severity.h>
#include <Uid.h>

class LogEngine : public QObject
{
    Q_OBJECT
public: // types


public: // ctors
    explicit LogEngine(QObject *parent = nullptr);

public slots:
    void capture();
    void release();
    void enqueue(const LogItem &li);
    void dequeue();

signals:
    void captured();
    void released();
    void enqueued(const LogItem &li);
    void dequeued(const LogItem &li);
    void empty();
    void count(const Count k);

public: // const
    bool isEmpty() const;

public: // non-const
    LogItem takeQueue();

public: // static
    static KeyTextMap parse(const QString s);
    static QString messagePattern();

private: // static
    static void messageHandler(QtMsgType qmt, const QMessageLogContext &ctx, const QString &s);
    static const QStringList scmMessageFields;

private:
    QtMessageHandler mOldHandler;
    QMap<Uid, LogItem> mUidItemMap;
    QMultiMap<Severity, Uid> mSevUidMMap;
};
