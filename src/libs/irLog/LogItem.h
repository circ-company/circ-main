#pragma once

#include <QMetaMethod>
#include <QMetaType>
#include <QVariant>
#include <QVariantList>

#include <CodeContext.h>
#include <KeyMap.h>
#include <MillisecondTime.h>
#include <StatusLevel.h>
#include <Uid.h>
#include <Types.h>

#include "LogClass.h"
#include "LogMsgType.h"

class CodeContext;

class LogItem
{
public: // types
    typedef Log::ItemType Type;

public: // ctors // TODO This really smells
    LogItem(const Type type, const StatusLevel &lvl, const CodeContext &ctx=CodeContext());

public: // const
    bool isNil() const;
    bool isNull() const;
    Milliseconds ems() const;
    MillisecondTime mst() const;
    Uid uid() const;
    Type type() const;
    StatusLevel level() const;
    CodeContext context() const;
    AText message() const;
    Count varCount() const;
    QVariant var(const Index ix) const;
    QVariantList vars() const;
    AText formatted() const;
    LogMsgType logMessageType() const;
    bool isFault() const;

public: // non-const
    void clear();
    void level(const StatusLevel aLevel);
    void type(const Type type);
    void context(const CodeContext &ctx);
    void format(const AText &aText);
    void op(const Log::Operator aOp);
    void text(const AText aVar);
    void set(const QVariant aVar);
    void set(const QVariantList aVarList);
    void pointer(void * aPtr, const char *aExpression);
    void assertIs(const Log::Operator aOp,
                  const bool aIs, const char *aExpression);
    void expect(const Log::Operator aOp, // True or False
                const QVariant aActVar, const char *aActText);
    void expect(const Log::Operator aOp, // Relational
                const QVariant aExpVar, const char *aExpText,
                const QVariant aActVar, const char *aActText);
    bool connect(QObject *sender, const QMetaMethod &signal,
                 QObject *receiver, const QMetaMethod &method,
                 const char *pchSender, const char *pchSignal,
                 const char *pchReceiver, const char *pchMethod);
    void * malloc(const Count nBytes, const AText &aArg);
    void newobj(QObject * pNewObj, const CText &aObjName, QObject * pParent);
    void dumpVar(const QVariant aVar, const char *aText);
    void dumpAll(const QVariant aVar, const char *aText);

public: // pointers

private:

private:
    Uid mUid;
    Milliseconds mEMS;
    Type mType;
    StatusLevel mLevel;
    CodeContext mContext;
    AText mFormat;
    Log::Operator mOperator=Log::$nullOperator;
    QVariantList mVarList;

public: // QMetaType
    const LogItem & it() const { return *this; }
    LogItem & it() { return *this; }
    LogItem() = default;
    ~LogItem() = default;
    LogItem(const LogItem &) = default;
    LogItem &operator=(const LogItem &) = default;
};

Q_DECLARE_METATYPE(LogItem);

inline bool LogItem::isNil() const { return uid().isNil(); }
inline bool LogItem::isNull() const { return Type::$nullType == type(); }
inline Milliseconds LogItem::ems() const { return mEMS; }
inline MillisecondTime LogItem::mst() const { return MillisecondTime(ems()); }
inline Uid LogItem::uid() const { return mUid; }
inline StatusLevel LogItem::level() const { return mLevel; }
inline LogItem::Type LogItem::type() const { return mType; }
inline CodeContext LogItem::context() const { return mContext; }
inline AText LogItem::message() const { return mFormat; }
inline Count LogItem::varCount() const { return vars().count(); }
inline QVariantList LogItem::vars() const { return mVarList; }
inline bool LogItem::isFault() const { return level().isFault(); }
inline void LogItem::level(const StatusLevel aLevel) { mLevel = aLevel; }
inline void LogItem::type(const Type type) { mType = type; }
inline void LogItem::context(const CodeContext &ctx) { mContext = ctx; }
inline void LogItem::format(const AText &aText) { mFormat = aText; }
inline void LogItem::set(const QVariant aVar) { mVarList.append(aVar); }
inline void LogItem::set(const QVariantList aVarList) { mVarList = aVarList; }
inline void LogItem::op(const Log::Operator aOp) { mOperator = aOp; }


