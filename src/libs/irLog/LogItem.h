#pragma once

#include <QMetaType>

#include <CodeValue.h>
#include <CodeContext.h>
#include <KeyMap.h>
#include <StatusLevel.h>
#include <Uid.h>

#include "LogClass.h"
#include "LogMsgType.h"
#include "LogOperator.h"

class CodeContext;

class LogItem
{
public: // types
    typedef Log::ItemType Type;

public: // ctors // TODO This really smells
    LogItem(const Type type, const CText &sevName, const CodeContext &ctx);
    LogItem(const Type type, const StatusLevel &slv, const CodeContext &ctx);

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
    CodeValue value() const;
    Count count() const;
    CodeValue value(const Index ix) const;

public: // non-const
    void clear();
    void set(const Type type);
    void set(const CodeContext &ctx);
    void set(const AText &msg);
    void set(const LogOperator::Enum op);
    void set(const CodeValue &cv);
    void set(const CodeValueList &cvs);
    void set(const Index ix, const CodeValue &cv);
    void asert(const LogOperator::Enum op, const bool is, const char *exp);

public: // pointers
    const CodeValueList codeValues() const;
    CodeValueList & codeValues();
    const LogItem & it() const;
    LogItem & it();

private:
    Uid mUid;
    Type mType;
    StatusLevel mLevel;
    CodeContext mContext;
    AText mMessage;
    LogOperator::Enum mOperator=LogOperator::Enum::$null;
    CodeValue mValue;
    CodeValueList mValues;

public: // QMetaType
    LogItem() = default;
    ~LogItem() = default;
    LogItem(const LogItem &) = default;
    LogItem &operator=(const LogItem &) = default;
};

Q_DECLARE_METATYPE(LogItem);

inline bool LogItem::isNil() const { return uid().isNil(); }
inline bool LogItem::isNull() const { return Type::$null == type(); }
inline Uid LogItem::uid() const { return mUid; }
inline StatusLevel LogItem::level() const { return mLevel; }
inline LogItem::Type LogItem::type() const { return mType; }
inline CodeContext LogItem::context() const { return mContext; }
inline AText LogItem::message() const { return mMessage; }
inline Count LogItem::count() const { return codeValues().count(); }
inline CodeValue LogItem::value(const Index ix) const { return codeValues().at(ix); }
inline void LogItem::set(const AText &msg) { mMessage = msg; }
inline void LogItem::set(const LogOperator::Enum op) { mOperator = op; }
inline void LogItem::set(const CodeValue &cv) { mValue = cv; }
inline const CodeValueList LogItem::codeValues() const { return mValues; }
inline CodeValueList &LogItem::codeValues() { return mValues; }
inline const LogItem &LogItem::it() const { return *this; }
inline LogItem &LogItem::it() { return *this; }
