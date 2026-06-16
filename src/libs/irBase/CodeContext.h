#pragma once


#include "CText.h"
#include "FSText.h"
#include "FileInfo.h"
#include "FunctionInfo.h"
#include "NanosecondTime.h"
#include "Types.h"

class CodeContext
{
public: // ctors
    CodeContext(const QString &qfi, const FSText &file, const int line);

public: // const
    bool isNull() const;
    Nanoseconds epochNS() const;
    NanosecondTime NSTime() const;
    CText qfiText() const;
    FSText baseFileName() const;
    FSText fileName() const;
    int fileLine() const;
    FunctionInfo funcInfo() const;
    FileInfo fileInfo() const;
    AText toString(const bool withTime=true) const;

public: // non-const
    void clear();

public: // pointers

public: // debug
    QString toDebugString(const bool fullTimeFirst=true) const;
    QStringList toDebugStrings() const;

private:
    Nanoseconds mEpochNS=0;
    CText mQFIText;
    FSText mFileName;
    int mFileLine=0;
    FunctionInfo mFuncInfo;
    FileInfo mFileInfo;


public: // QMetaType
    CodeContext() = default;
    ~CodeContext() = default;
    CodeContext(const CodeContext &) = default;
    CodeContext &operator=(const CodeContext &) = default;
};

inline bool CodeContext::isNull() const { return 0 == epochNS(); }
inline Nanoseconds CodeContext::epochNS() const { return mEpochNS; }
inline NanosecondTime CodeContext::NSTime() const { return NanosecondTime(epochNS()); }
inline CText CodeContext::qfiText() const { return mQFIText; }
inline FSText CodeContext::fileName() const { return mFileName; }
inline int CodeContext::fileLine() const { return mFileLine; }
inline FunctionInfo CodeContext::funcInfo() const { return mFuncInfo; }
inline FileInfo CodeContext::fileInfo() const { return mFileInfo; }

Q_DECLARE_METATYPE(CodeContext);


