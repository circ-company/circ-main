#pragma once

#include <QSharedDataPointer>

#include "AText.h"
#include "CText.h"

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
