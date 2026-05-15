#pragma once

#include <QSharedDataPointer>

#include "AText.h"
#include "CText.h"
#include "CTextList.h"
#include "CodeArgument.h"
#include "CodeArgumentList.h"
#include "Types.h"


class FunctionInfoData;

class FunctionInfo
{
public:
    FunctionInfo();
    FunctionInfo(const AText &atx);
    FunctionInfo(const FunctionInfo &);
    ~FunctionInfo();
    FunctionInfo(FunctionInfo &&);
    FunctionInfo &operator=(const FunctionInfo &);
    FunctionInfo &operator=(FunctionInfo &&);

public: // const
    bool isNull() const;
    Count argCount() const;
    CodeArgument arg(const Index argix) const;

public: // non-const
    void set(const CText &ctx);

private:
    QSharedDataPointer<FunctionInfoData> data;
};
