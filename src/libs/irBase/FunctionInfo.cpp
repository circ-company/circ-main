#include "FunctionInfo.h"

#include <utility>

#include "ArgumentInfo.h"
#include "ArgumentInfoList.h"

class FunctionInfoData : public QSharedData
{
public:
    AText               dQFIString;
    CTextList           dReturnType;
    CTextList           dAnte;
    CText               dNamespaces;
    CText               dClassName;
    CText               dFunctionName;
    ArgumentInfoList    dArgumentList;
    CTextList           dPost;
    int                 dFuncInfoFlags;
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

ArgumentInfo FunctionInfo::arg(const Index argix) const
{
    Q_CHECK_PTR(data);
    return (argix >= 0 && argix < Index(argCount()))
               ? data->dArgumentList.at(argix)
               : ArgumentInfo();
}

CText FunctionInfo::completeBaseName() const
{
    Q_CHECK_PTR(data);
    CText result;
    if ( ! data->dClassName.isEmpty())
        result += data->dClassName() + "::";
    result += data->dFunctionName() + "()";
    return result;
}

void FunctionInfo::clear()
{
    Q_CHECK_PTR(data);
    data->dQFIString.clear();
    // TODO remaining
}

void FunctionInfo::set(const CText &ctx)
{
    Q_CHECK_PTR(data);
    data->dQFIString = ctx;
    parse();
}

void FunctionInfo::parse()
{
    Q_CHECK_PTR(data);
    AText tInput = data->dQFIString;
    const int cFirstOpenParenPos = tInput.indexOf('(');
    if (cFirstOpenParenPos < 0) return;                         /*/=====\*/
    AText tFront = tInput.left(cFirstOpenParenPos);
    const int cFrontLastSpacePos = tFront.lastIndexOf(' ');
    AText tAnte, tNames;
    if (cFrontLastSpacePos < 1)
    {
        tNames = tFront;
    }
    else
    {
        tAnte = tFront.left(cFrontLastSpacePos - 1);
        tNames = tFront.mid(cFrontLastSpacePos + 1);
    }
    CTextList tNameList = tNames.split("::");
    CText tFuncName = tNameList.isEmpty() ? CText() : tNameList.takeLast();
    CText tClassName = tNameList.isEmpty() ? CText() : tNameList.takeLast();
    CText tNamespaces = tNameList.join("::");
    // TODO Arguments, post
    // TODO parse flags
    data->dNamespaces = tNamespaces,
        data->dClassName = tClassName,
        data->dFunctionName = tFuncName;
}

QString FunctionInfo::toDebugString() const
{
    Q_CHECK_PTR(data);
    return QString("{FunctionInfo: %1}").arg(data->dQFIString());
}

QStringList FunctionInfo::toDebugStrings() const
{
    QStringList result;
    Q_CHECK_PTR(data);
    result << QString("{==Function Info:          %1").arg(data->dQFIString());
    result << QString("---Return Type:            %1").arg(data->dReturnType.join(',')());
    result << QString("---Ante:                   %1").arg(data->dAnte.join(',')());
    result << QString("---Namespaces:             %1").arg(data->dNamespaces());
    result << QString("---Class Name:             %1").arg(data->dClassName());
    result << QString("---Function Name:          %1").arg(data->dFunctionName());
    result << QString("---Arguments:              %1").arg(argCount());
    for (Index ix = 0; ix < Index(argCount()); ++ix)
        result << QString("   %1.                    %2").arg(arg(ix).toDebugString());
    result << QString("---Post:                   %1}").arg(data->dPost.join(',')());
    return result;
}
