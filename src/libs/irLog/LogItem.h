#pragma once

#include <QMetaType>

#include <ArgumentInfo.h>
#include <ArgumentInfoList.h>
#include <CodeContext.h>
#include <KeyMap.h>
#include <StatusLevel.h>
#include <Uid.h>

#include "LogClass.h"
#include "LogMsgType.h"

class CodeContext;

class LogItem
{
public: // types
    typedef Log::ItemType Type;

public: // ctors // TODO This really smells
    LogItem(const Type type, const StatusLevel &lvl, const CodeContext &ctx);

public: // const
    bool isNil() const;
    bool isNull() const;
    Uid uid() const;
    Type type() const;
    StatusLevel level() const;
    CodeContext context() const;
    AText message() const;
    AText formatted() const;
    LogMsgType logMessageType() const;
    ArgumentInfo argument() const;
    Count count() const;
    ArgumentInfo argument(const Index ix) const;

public: // non-const
    void clear();
    void level(const StatusLevel aLevel);
    void set(const Type type);
    void set(const CodeContext &ctx);
    void set(const AText &msg);
    void set(const Log::Operator op);
    void set(const ArgumentInfo &ai);
    void set(const ArgumentInfoList &cvs);
    void set(const Index ix, const ArgumentInfo &cv);
    void assertIs(const Log::Operator aOp,
                  const bool aIs, const char *aExpression);
    void expect(const Log::Operator aOp, // True or False
                const QVariant aActVar, const char *aActText);
    void expect(const Log::Operator aOp, // Relational
                const QVariant aExpVar, const char *aExpText,
                const QVariant aActVar, const char *aActText);
    void * malloc(const Count nBytes, const AText &aArg);
    void newobj(QObject * pNewObj, const CText &aObjName, const AText &aObjType,
                QObject * pParent, const CText &aParentType);

public: // pointers
    const ArgumentInfoList arguments() const;
    ArgumentInfoList & arguments();
    const LogItem & it() const;
    LogItem & it();

private:
    AText formatValues() const;

private:
    Uid mUid;
    Type mType;
    StatusLevel mLevel;
    CodeContext mContext;
    AText mMessage;
    Log::Operator mOperator=Log::$nullOperator;
    ArgumentInfo mValue;
    ArgumentInfoList mValues;

public: // QMetaType
    LogItem() = default;
    ~LogItem() = default;
    LogItem(const LogItem &) = default;
    LogItem &operator=(const LogItem &) = default;
};

Q_DECLARE_METATYPE(LogItem);

inline bool LogItem::isNil() const { return uid().isNil(); }
inline bool LogItem::isNull() const { return Type::$nullType == type(); }
inline Uid LogItem::uid() const { return mUid; }
inline StatusLevel LogItem::level() const { return mLevel; }
inline LogItem::Type LogItem::type() const { return mType; }
inline CodeContext LogItem::context() const { return mContext; }
inline AText LogItem::message() const { return mMessage; }
inline Count LogItem::count() const { return arguments().count(); }
inline ArgumentInfo LogItem::argument(const Index ix) const { return arguments().at(ix); }
inline void LogItem::level(const StatusLevel aLevel) { mLevel = aLevel; }
inline void LogItem::set(const AText &msg) { mMessage = msg; }
inline void LogItem::set(const Log::Operator op) { mOperator = op; }
inline void LogItem::set(const ArgumentInfo &ai) { mValue = ai; }
inline const ArgumentInfoList LogItem::arguments() const { return mValues; }
inline ArgumentInfoList &LogItem::arguments() { return mValues; }
inline const LogItem &LogItem::it() const { return *this; }
inline LogItem &LogItem::it() { return *this; }
