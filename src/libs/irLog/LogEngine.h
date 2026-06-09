#pragma once

#include <QObject>

#include <QCoreApplication>
#include <QQueue>
#include <QStringList>

#include <StatusLevel.h>
#include <Uid.h>

#include "LogItem.h"

class LogEngine : public QObject
{
    Q_OBJECT
public: // types
    typedef Log::ItemType Type;

public: // ctors
    explicit LogEngine();

public slots:
    void capture();
    void release();
    void enqueue(LogItem li);
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
    void sendTroll(const LogItem &li);
    void writeTroll(const LogMsgType lmt, const AText atx);

public: // static
    static KeyTextMap parse(const QString s);
    static QString messagePattern();

private: // static
    static void messageHandler(QtMsgType qmt, const QMessageLogContext &ctx, const QString &s);
    static const QStringList scmMessageFields;

private:
    bool mCaptured=false;
    bool mTrollEnabled=true;
    QtMessageHandler mpOldHandler;
    QMap<Uid, LogItem> mUidItemMap;
    QMultiMap<StatusLevel, Uid> mLevelUidMMap;
};

Q_GLOBAL_STATIC(LogEngine, LOG);
