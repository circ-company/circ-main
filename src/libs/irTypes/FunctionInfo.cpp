#include "FunctionInfo.h"

#include <utility>

#include <QList>


class FunctionInfoData : public QSharedData
{
public:
    CText           dQFIString;
    CTextList       dReturnType;
    CTextList       dAnte;
    CTextList       dNamespaces;
    CText           dClassName;
    CText           dFunctionName;
    CodeArgumentList dArgumentList;
    CTextList       dPost;
    int             dFuncInfoFlags;
};

FunctionInfo::FunctionInfo() : data(new FunctionInfoData) {;}
FunctionInfo::FunctionInfo(const AText &atx)  : data(new FunctionInfoData) { set(atx); }
FunctionInfo::FunctionInfo(const FunctionInfo &rhs) : data{rhs.data} {;}
FunctionInfo::FunctionInfo(FunctionInfo &&rhs) : data{std::move(rhs.data)} {;}
FunctionInfo::~FunctionInfo() {;}

FunctionInfo &FunctionInfo::operator=(const FunctionInfo &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

FunctionInfo &FunctionInfo::operator=(FunctionInfo &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

bool FunctionInfo::isNull() const
{
    Q_CHECK_PTR(data);
    return data->dQFIString.isEmpty();
}

Count FunctionInfo::argCount() const
{
    Q_CHECK_PTR(data);
    return data->dArgumentList.count();
}

CodeArgument FunctionInfo::arg(const Index argix) const
{
    Q_CHECK_PTR(data);
    return (argix >= 0 && argix < Index(argCount()))
               ? data->dArgumentList.at(argix)
               : CodeArgument();
}

void FunctionInfo::set(const CText &ctx)
{
    Q_CHECK_PTR(data);
    data->dQFIString = ctx;
}
