#pragma once

#include "CText.h"
#include "FileInfo.h"
#include "FSText.h"
#include "FunctionInfo.h"
#include "Types.h"

class CodeContext
{
public:
    CodeContext(const QString &qfi, const FSText &file, const int line);

private:
    Nanoseconds mEpochNS;
    CText mQFIText;
    FSText mFileName;
    int mFileLine;
    FunctionInfo mFuncInfo;
    FileInfo mFileInfo;


public: // QMetaType
    CodeContext() = default;
    ~CodeContext() = default;
    CodeContext(const CodeContext &) = default;
    CodeContext &operator=(const CodeContext &) = default;
};

Q_DECLARE_METATYPE(CodeContext);

#define CODECONTEXT() { const CodeContext cContext(Q_FUNC_INFO, __FILE__, __LINE__); }

