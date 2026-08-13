#include "SettingsFile.h"

#include <QTemporaryFile>

#include <DocParseResult.h>
#include <Log.h>
#include <TriBool.h>
#include <XmlDocFile.h>

SettingsFile::SettingsFile(QSettings::Format aFormat, QObject *parent)
    : QObject(parent)
{
    QTemporaryFile tTempFile("XXXXXX.ini");
    QString tFileName = tTempFile.fileName();
    ctor(tFileName, aFormat);
}

SettingsFile::SettingsFile(const QString &aFileName, QSettings::Format aFormat, QObject *parent)
    : QObject(parent)
{
    ctor(aFileName, aFormat);
}

void SettingsFile::ctor(const QString &aFileName, QSettings::Format aFormat)
{
    mpSettings = new QSettings(aFileName, aFormat, this);
    NEWOBJ(mpSettings, QSettings, this);
    mXmlFormat = registerXml();
    WEXPECTNE(QSettings::Format::InvalidFormat, mXmlFormat);
}

QSettings::Format SettingsFile::registerXml()
{
    Q_CHECK_PTR(mpSettings);
    return mpSettings->registerFormat("xml", &xmlReadFunc, &xmlWriteFunc);
}

/* ------------------ static private -------------------- */

bool SettingsFile::xmlReadFunc(QIODevice &aDevice,
                               QSettings::SettingsMap &aMap)
{
    TriBool result;
    QDomDocument tDoc;
    const DocParseResult cDocResult = tDoc.setContent(&aDevice);
    WEXPECTIS(cDocResult.ok());
    if (cDocResult.ok())
    {
        aMap = parseXmlDoc(tDoc);
    }
    else
    {
        result.set(false);
        WARNMSG(cDocResult.toString());
    }
    return result;
}

bool SettingsFile::xmlWriteFunc(QIODevice &aDevice, const QSettings::SettingsMap &aMap)
{
    TriBool result;

    return result;
}

QSettings::SettingsMap SettingsFile::parseXmlDoc(const QDomDocument aDoc)
{
    QSettings::SettingsMap result;
    const QDomElement cRootElement = aDoc.documentElement();
    const QString cRootName = cRootElement.localName();
    DUMPVAR(cRootName);
    return result;
}

