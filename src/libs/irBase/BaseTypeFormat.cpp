#include "BaseTypeFormat.h"

#include "FileInfo.h"
#include "Url.h"

void BaseTypeFormat::registerBase()
{
    const int cTypeIdFI = QMetaType::fromName("FileInfo").id();
    const int cTypeIdUrl = QMetaType::fromName("Url").id();
//    Q_ASSERT(cTypeIdFI); Q_ASSERT(cTypeIdUrl);
    registerFunction(cTypeIdFI, &formatFileInfo);
    registerFunction(cTypeIdUrl, &formatUrl);

}

AText BaseTypeFormat::formatFileInfo(const QVariant &aVar)
{
    AText result;
    FileInfo tFI = aVar.value<FileInfo>();
    result = QString("Url:<%1> Exists=%2").arg(tFI.toString()).arg(tFI.exists());
    return result;
}

AText BaseTypeFormat::formatUrl(const QVariant &aVar)
{
    AText result;
    Url tUrl = aVar.value<Url>();
    result = QString("Url:<%1> Type=%2").arg(tUrl.toString()).arg(tUrl.type());
    return result;
}
