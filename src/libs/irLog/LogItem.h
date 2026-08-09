#pragma once

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
    bool isList() const;
    bool isFault() const;

public: // non-const
    void clear();
    void level(const StatusLevel aLevel);
    void set(const Type type);
    void set(const CodeContext &ctx);
    void set(const AText &aText);
    void set(const QVariant aVar);
    void set(const QVariantList aVarList);
    void set(const Log::Operator op);
    void assertIs(const Log::Operator aOp,
                  const bool aIs, const char *aExpression);
    void expect(const Log::Operator aOp, // True or False
                const QVariant aActVar, const char *aActText);
    void expect(const Log::Operator aOp, // Relational
                const QVariant aExpVar, const char *aExpText,
                const QVariant aActVar, const char *aActText);
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
    QVariantList mVarList;
    Log::Operator mOperator=Log::$nullOperator;

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

inline void LogItem::set(const QVariant aVar) { mVarList.append(aVar); }
inline void LogItem::set(const QVariantList aVarList) { mVarList = aVarList; }
inline void LogItem::set(const Log::Operator op) { mOperator = op; }


