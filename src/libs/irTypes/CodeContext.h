#pragma once

#include <QQFileInfo.h>

#include "CText.h"
#include "FSText.h"
#include "FunctionInfo.h"
#include "Types.h"

class CodeContext
{
public: // ctors
    CodeContext(const QString &qfi, const FSText &file, const int line);

public: // debug
    QString toDebugString() const;
    QStringList toDebugStrings() const;

private:
    Nanoseconds mEpochNS;
    CText mQFIText;
    FSText mFileName;
    int mFileLine;
    FunctionInfo mFuncInfo;
    QQFileInfo mFileInfo;


public: // QMetaType
    CodeContext() = default;
    ~CodeContext() = default;
    CodeContext(const CodeContext &) = default;
    CodeContext &operator=(const CodeContext &) = default;
};

Q_DECLARE_METATYPE(CodeContext);

#define CODECONTEXT() { const CodeContext cContext(Q_FUNC_INFO, __FILE__, __LINE__); }

