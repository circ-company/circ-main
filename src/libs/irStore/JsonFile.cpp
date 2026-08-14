#include "JsonFile.h"

#include <QTimer>

#include <Log.h>

JsonFile::JsonFile(QObject *parent)
    : TextFile{parent}
{
    setObjectName("JsonFile:Null");
}

JsonFile::JsonFile(const FileInfo &aFI,
                   const QIODeviceBase::OpenMode aMode,
                   QObject *parent)
    : TextFile(aFI, aMode | QIODevice::Text, parent)
{
    setObjectName("JsonFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
                       {
                           emit infoSet(fileInfo(), exists());
                           emit modeSet(fileInfo(), mode());
                       });
}

JsonFile::JsonFile(const FSText &aFName,
                   const QIODeviceBase::OpenMode aMode,
                   QObject *parent)
    : TextFile(aFName, aMode | QIODevice::Text, parent)

{
    setObjectName("JsonFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
                       {
                           emit infoSet(fileInfo(), exists());
                           emit modeSet(fileInfo(), mode());
                       });
}

void JsonFile::clear()
{
    mDocument = QJsonDocument();
    mParseError = QJsonParseError();
}

bool JsonFile::read()
{
    FNENTER();
    clear();
    bool result = TextFile::read();
    if (result)
        mDocument = QJsonDocument::fromJson((TextFile::data().toQBA()), &mParseError);
    logFunction.returnValue(result, "result", "bool");
//    FNRETURN(result, bool);
    return result;
}

SQWORD JsonFile::errorOffset() const
{
    const std::conditional_t<6 < 7, int, qint64> cStdOff = mParseError.offset;
    return (QJsonParseError::NoError == error()) ? 0LL : (qint64)cStdOff;
}
