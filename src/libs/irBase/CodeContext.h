#pragma once

#include "CText.h"
#include "FSText.h"
#include "FileInfo.h"
#include "FunctionInfo.h"
#include "Types.h"

class CodeContext
{
public: // ctors
    CodeContext(const QString &qfi, const FSText &file, const int line);

public: // const
    bool isNull() const;
    bool isSameFunction(const CodeContext &other) const;
    CText qfiText() const;
    FSText baseFileName() const;
    FSText lineTime() const;
    FSText fileName() const;
    int fileLine() const;
    FunctionInfo funcInfo() const;
    FileInfo fileInfo() const;
    AText toString() const;
    static Count functionLevel();

public: // non-const
    void clear();
    static Count increaseLevel();
    static Count decreaseLevel();

public: // pointers

public: // debug
    QString toDebugString(const bool fullTimeFirst=true) const;
    QStringList toDebugStrings() const;

private:
    Milliseconds mEpochMS=0;
    CText mQFIText;
    FSText mFileName;
    int mFileLine=0;
    Count mFunctionLevel;
    FunctionInfo mFuncInfo;
    FileInfo mFileInfo;
    static Count smLevel;

public: // QMetaType
    const CodeContext & it() const { return *this; }
    CodeContext & it() { return *this; }
    CodeContext() = default;
    ~CodeContext() = default;
    CodeContext(const CodeContext &) = default;
    CodeContext &operator=(const CodeContext &) = default;
};

inline bool CodeContext::isNull() const { return 0 == mEpochMS; }
inline CText CodeContext::qfiText() const { return mQFIText; }
inline FSText CodeContext::fileName() const { return mFileName; }
inline int CodeContext::fileLine() const { return mFileLine; }
inline FunctionInfo CodeContext::funcInfo() const { return mFuncInfo; }
inline FileInfo CodeContext::fileInfo() const { return mFileInfo; }

Q_DECLARE_METATYPE(CodeContext);

#define CODECONTEXT() CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)


