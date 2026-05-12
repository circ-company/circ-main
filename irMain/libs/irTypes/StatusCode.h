#pragma once

#include <QSharedDataPointer>
#include "DataProperty.h"

#ifdef STATUS_UTEXT
#include <UText.h>
#include "UTextList.h"
#define FORMAT UText
#define FORMATLIST UTextList
#else
#include <AText.h>
#include "ATextList.h"
#define FORMAT AText
#define FORMATLIST ATextList
#endif

#include <QList>

#include <Severity.h>

#include "CodeContext.h"
#include "CText.h"
#include "CTextList.h"
#include "NanosecondTime.h"
#include "StatusCodeArgument.h"
#include "Types.h"


#define STATUSCODE_DATAPROPS(TND) \
    TND(Nanoseconds, NSTimeStamp, 0) \
    TND(int, SeverityCode, 0) \
    TND(CodeContext, Context, CodeContext()) \
    TND(FORMAT, Format, FORMAT()) \
    TND(StatusCodeArgumentList, Arguments, StatusCodeArgumentList()) \

class StatusCodeData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(STATUSCODE_DATAPROPS);
public:
    StatusCodeData(void)
    {
        DEFINE_DATAPROPS_CTORS(STATUSCODE_DATAPROPS);
    }
};

class StatusCode
{
public: // types
    typedef QList<StatusCode> List;

public: // ctors
    StatusCode(const CodeContext &ctx, const Severity sev, const FORMAT msg=FORMAT());
    StatusCode(const CodeContext &ctx, const Severity sev, const FORMAT msg,
               const StatusCodeArgument &arg1,
               const StatusCodeArgument &arg2=StatusCodeArgument(),
               const StatusCodeArgument &arg3=StatusCodeArgument(),
               const StatusCodeArgument &arg4=StatusCodeArgument());
    StatusCode(const CodeContext &ctx, const Severity sev, const FORMAT msg,
               const StatusCodeArgumentList &args);


public: // const
    bool isNull() const;
    Severity severity() const;
    FORMAT formattedMessage() const;
    FORMATLIST formattedMessageArgs() const;
    Count argumentCount() const;
    bool isValidArgumentIndex(const Index ix) const;
    StatusCodeArgument argument(const Index ix) const;

public: // non-const

public:
    DECLARE_PARENT_DATAPROPS(STATUSCODE_DATAPROPS)
    DECLARE_DATAPROPS(StatusCode, StatusCodeData)
};

inline Severity StatusCode::severity() const { return Severity(SeverityCode()); }
