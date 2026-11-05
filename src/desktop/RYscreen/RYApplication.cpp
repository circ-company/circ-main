#include "RYApplication.h"

#include <Log.h>

RYApplication::RYApplication(int argc, char *argv[])
    : Application(argc, argv)
{
    FNENTER();
    setObjectName("RYApplication");
    mArguments = arguments();
}
/*
void RYApplication::initialize()
{
    foreach (const QString cArg, mArguments)
    {
        if (cArg.startsWith('$'))
        {
            QFileInfo tJsonFI = QFileInfo(cArg.mid(1));
            if (tJsonFI.exists() && tJsonFI.isReadable())
            {
                QFile tJsonFile(tJsonFI.filePath(), this);
                if (tJsonFile.isReadable())
                {
                    const QByteArray cJsonBytes = tJsonFile.readAll();
                    QJsonParseError tJsonError;
                    QJsonDocument tJsonDoc = QJsonDocument::fromJson(cJsonBytes, &tJsonError);
                    if (tJsonError.error == QJsonParseError::NoError)
                        mJsonDoc = tJsonDoc;
                }
            }
        }
    }
    if (mJsonDoc.isEmpty())
    {
        WARNING("No JSON configuration");
    }
    else
    {
        DUMPVAR(mJsonDoc);
    }
}
*/
