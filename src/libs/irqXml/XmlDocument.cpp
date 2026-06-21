#include "XmlDocument.h"

#include <CodeContext.h>
#include <Log.h>
#include <StatusItem.h>

XmlDocument::XmlDocument(const FileInfo &aFI) { set(aFI); }

bool XmlDocument::isOpen() const
{
    bool result = false;
    if (mpFile && mpFile->isOpen())
        result = true;
    return result;
}

bool XmlDocument::set(const FileInfo &aFI)
{
    mFileInfo.setFile(aFI.filePath());
    return mFileInfo.exists();
}

void XmlDocument::close()
{
    if (isOpen())
        if (mpFile)
        {
            mpFile->close();
        }

}

Result XmlDocument::readAll()
{
    Result result(CODECONTEXT());
    StatusItem tStartStatus("CIRCCOcom/circ-main/irqXml/XmlDocument/readAll", CODECONTEXT());
    tStartStatus.add(mFileInfo.toVariant());
    result.add(tStartStatus);

    StatusItem tOpenStatus("CIRCCOcom/circ-main/irqXml/XmlDocument/readAll/OpenFile", CODECONTEXT());

    result.add(tOpenStatus);

    return result;
}
