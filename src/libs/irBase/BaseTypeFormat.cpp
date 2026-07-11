#include "BaseTypeFormat.h"

#include "FileInfo.h"
#include "Url.h"

void BaseTypeFormat::registerBase()
{
    const int cTypeIdFI = 65584; // TODO: QMetaType::fromName("FileInfo").id();
// TODO:    const int cTypeIdUrl = QMetaType::fromName("Url").id();
    Q_ASSERT(cTypeIdFI); // Q_ASSERT(cTypeIdUrl);
    registerFunction(cTypeIdFI, &formatFileInfo);
    //registerFunction(cTypeIdUrl, &formatUrl);

}

AText BaseTypeFormat::formatFileInfo(const QVariant &aVar)
{
    AText result;
    FileInfo tFI = aVar.value<FileInfo>();
    result = QString("FileInfo:<%1>").arg(tFI.toString());
    return result;
}

AText BaseTypeFormat::formatUrl(const QVariant &aVar)
{
    AText result;
    Url tUrl = aVar.value<Url>();
    result = QString("Url:<%1> Type=%2").arg(tUrl.toString()).arg(tUrl.type());
    return result;
}
