#pragma once

#include <QSharedDataPointer>

#include "AText.h"
#include "ArgumentInfo.h"
#include "CText.h"
#include "CTextList.h"
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
    ArgumentInfo arg(const Index argix) const;
    CText completeBaseName() const;

public: // non-const
    void clear();
    void set(const CText &ctx);
    void parse();

public: // debug
    QString toDebugString() const;
    QStringList toDebugStrings() const;

private:
    QSharedDataPointer<FunctionInfoData> data;
};
