#pragma once

#include <QObject>

#include <QtDebug>

class boostLogEngine : public QObject
{
    Q_OBJECT
public: // types
    enum Class
    {
        $nullClass      = 0,
        Develop,
        User,
        Data,
        Caution,
        $maxClass
    };

    enum Type
    {
        $nullType       = -1,
        Info            = QtInfoMsg,
        Debug           = QtDebugMsg,
        Warning         = QtWarningMsg,
        Critical        = QtCriticalMsg,
        Fatal           = QtFatalMsg,
    };

    enum Level
    {
        $nullLevel      = 0,
        Detail,         // Develop
        FnLeave,
        FnEmit,
        FnArgVal,
        FnEnter,
        DumpVar,
        Dump,
        Trace,
        TWarn,
        TError,
        Message,        // Info
        Progress,
        Record,         // Data
        Summary,
        Warn,           // Caution
        Error,
        Fault,
        $maxLevel
    };

public: // ctors
    explicit boostLogEngine();

public slots:

signals:

public: // const

public: // non-const

public: // static
    static Class classOf(const Level aLevel);
    static bool isDevelop(const Level aLevel);
    static bool isUser(const Level aLevel);
    static bool isData(const Level aLevel);
    static bool isCaution(const Level aLevel);

    static QtMsgType msgTypeOf(const Level aLevel);
    static Type typeOf(const Level aLevel);
    static bool isInfo(const Level aLevel);
    static bool isDebug(const Level aLevel);
    static bool isWarning(const Level aLevel);
    static bool isCritical(const Level aLevel);
    static bool isFatal(const Level aLevel);

private:

    // =================== PROPERTIES =====================
private:
};
