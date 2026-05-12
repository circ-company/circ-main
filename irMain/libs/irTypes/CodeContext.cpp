#include "CodeContext.h"


CodeContext::CodeContext(const QString &qfi, const FSText &file, const int line)
    : mQFIText(qfi)
    , mFileName(file)
    , mFileLine(line)
    , mFuncInfo(mQFIText)
    , mFileInfo(mFileName)
{;}
