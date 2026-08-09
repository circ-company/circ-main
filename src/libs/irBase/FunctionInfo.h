#pragma once

#include <QSharedDataPointer>

#include <QList>

#include "AText.h"
#include "ATextList.h"
#include "CText.h"

class FunctionInfoData;

class FunctionInfo
{
public: // types
    enum Flag
    {
        $null           = 0,
        Void            = 0x80000000,
        AnteConst       = 0x40000000,

        PostConst       = 0x00000001,
    };

    struct Argument
    {
        AText       Text;
        ATextList   Ante;
        AText       Type;
        CText       Name;
        AText       Default;
    };
    typedef QList<Argument> ArgumentList;

public: // ctors
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
    CText namespaces() const;

public: // non-const
    void clear();
    void set(const CText &ctx);
    void parse();

private: // non-const
    void parseArguments(const AText aArgs);

public: // debug
    QString toDebugString() const;
    QStringList toDebugStrings() const;

private:
    QSharedDataPointer<FunctionInfoData> data;
    ArgumentList mArgList;
};
