#include "FunctionInfo.h"

#include <utility>

#include "CTextList.h"

class FunctionInfoData : public QSharedData
{
public:
    AText               dQFIString;
    CTextList           dReturnType;
    CTextList           dAnte;
    CTextList           dNamespaceList;
    CText               dClassName;
    CText               dFunctionName;
    FunctionInfo::ArgumentList  dArgumentList;
    CTextList           dPost;
    int                 dFuncInfoFlags;
};

FunctionInfo::FunctionInfo() : data(new FunctionInfoData) {;}
FunctionInfo::FunctionInfo(const AText &aQfiText)  : data(new FunctionInfoData) { set(aQfiText); }
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

CText FunctionInfo::completeBaseName() const
{
    Q_CHECK_PTR(data);
    CText result;
    if ( ! data->dClassName.isEmpty())
        result += data->dClassName() + "::";
    result += data->dFunctionName() + "()";
    return result;
}

CText FunctionInfo::namespaces() const
{
    Q_CHECK_PTR(data);
    return data->dNamespaceList.join("::");
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
    AText tInput = data->dQFIString.simplified();
    const int cFirstOpenParenPos = tInput.indexOf('(');
    Q_ASSERT(cFirstOpenParenPos > 1);

    AText tFront = tInput.left(cFirstOpenParenPos);
    const int cFrontLastSpacePos = tFront.lastIndexOf(' ');
    AText tAnte = tFront.left(cFrontLastSpacePos - 1);
    AText tNames = tFront.mid(cFrontLastSpacePos + 1);
    CTextList tNameList = tNames.split("::");
    CText tFuncName = tNameList.isEmpty() ? CText() : tNameList.takeLast();
    CText tClassName = tNameList.isEmpty() ? CText() : tNameList.takeLast();
    CTextList tNamespaceList = tNameList;

    AText tArgs = tInput.mid(cFirstOpenParenPos + 1);
    const int tArgsLastParenPos = tArgs.lastIndexOf(')');
    Q_ASSERT(tArgsLastParenPos >= 0);
    tArgs.chop(tArgsLastParenPos);
    if ( ! tArgs.isEmpty())
        parseArguments(tArgs);

    AText tBack = tArgs.mid(tArgsLastParenPos).simplified();

    // TODO parse flags
    data->dNamespaceList = tNamespaceList,
        data->dClassName = tClassName,
        data->dFunctionName = tFuncName;
}

void FunctionInfo::parseArguments(const AText aArgs)
{
    mArgList.clear();
    ATextList tArgsList = aArgs.split(',');
    foreach (AText aArg, tArgsList)
    {
        Argument Arg;
        aArg = aArg.simplified();
        Arg.Text = aArg;
        const int cEqualsPos = aArg.indexOf('=');
        if (cEqualsPos > 1)
        {
            Arg.Default = aArg.mid(1 + cEqualsPos);
            aArg.chop(cEqualsPos);
        }
        ATextList aArgParts = aArg.simplified().split(' ');
        if ( ! aArgParts.isEmpty())     Arg.Name = aArgParts.takeLast();
        if ( ! aArgParts.isEmpty())     Arg.Type = aArgParts.takeLast();
        Arg.Ante = aArgParts.join(' ');
        mArgList.append(Arg);
    }
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
    result << QString("---Namespaces:             %1").arg(namespaces()());
    result << QString("---Class Name:             %1").arg(data->dClassName());
    result << QString("---Function Name:          %1").arg(data->dFunctionName());
//    result << QString("---Arguments:              %1").arg(argCount());
  //  for (Index ix = 0; ix < Index(argCount()); ++ix)
    //    result << QString("   %1.                    %2").arg(arg(ix).toDebugString());
    result << QString("---Post:                   %1}").arg(data->dPost.join(',')());
    return result;
}
