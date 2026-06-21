#pragma once

#include <List.h>

#include <QMetaType>

#include <AText.h>
#include <ATextList.h>
#include <Id.h>
#include <List.h>
#include <StatusLevel.h>
#include <Types.h>

#include "CodeContext.h"
#include "CodeValue.h"
#include "CodeValueList.h"

class StatusCode : public Id
{
public: // types
    typedef ListT<StatusCode> List;

public: // ctors
    StatusCode(const Key &aKey);
    StatusCode(const Key &aKey, const StatusLevel aLevel,
               const AText aMessage=AText(), const AText aDesc=AText());
    StatusCode(const Key &aKey, const StatusLevel aLevel,
               const AText aFormat,
               const CodeValue &arg1,
               const CodeValue &arg2=CodeValue(),
               const CodeValue &arg3=CodeValue(),
               const CodeValue &arg4=CodeValue(),
               const AText aDesc=AText());
    StatusCode(const Key &aKey, const StatusLevel lvl,
               const AText aFormat,
               const CodeValueList &aValues,
               const AText aDesc=AText());

public: // const
    bool isNull() const;
    StatusLevel level() const;
    AText formatted() const;
    ATextList formattedMulti() const;
    Count argumentCount() const;
    bool isValidArgumentIndex(const Index ix) const;
    CodeValue argument(const Index ix) const;

public: // non-const
    void set(const Key &aKey, const StatusLevel aLevel,
             const AText aFormat,
             const CodeValueList &aValues,
             const AText aDesc=AText());

public: // pointers

private:
    StatusLevel mLevel=StatusLevel::Invalid;
    CodeContext mContext;
    AText mFormat;
    AText mDescription;
    CodeValueList mValues;

public: // QMetaType
    StatusCode() = default;
    ~StatusCode() = default;
    StatusCode(const StatusCode &) = default;
    StatusCode &operator=(const StatusCode &) = default;
    StatusCode & it() { return *this; }
    const StatusCode & it() const { return *this; }
};

Q_DECLARE_METATYPE(StatusCode);

inline bool StatusCode::isNull() const { return ! level().isValid(); }
inline StatusLevel StatusCode::level() const { return mLevel;; }
inline Count StatusCode::argumentCount() const { return mValues.count(); }
inline bool StatusCode::isValidArgumentIndex(const Index ix) const { return mValues.isValidIndex(ix); }
inline CodeValue StatusCode::argument(const Index ix) const { return mValues.at(ix); }
