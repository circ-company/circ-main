#pragma once

#include <QObject>

#include <QDomDocument>
#include <QSettings>

class SettingsFile : public QObject
{
    Q_OBJECT
public: // ctors
    explicit SettingsFile(QSettings::Format aFormat=QSettings::IniFormat, QObject *parent = nullptr);
    SettingsFile(const QString &aFileName, QSettings::Format aFormat=QSettings::IniFormat, QObject *parent = nullptr);
    void ctor(const QString &aFileName, QSettings::Format aFormat);

    QSettings::Format registerXml();

private: // static
    static bool xmlReadFunc(QIODevice &aDevice,
                            QSettings::SettingsMap &aMap);
    static bool xmlWriteFunc(QIODevice &aDevice,
                             const QSettings::SettingsMap &aMap);
    static QSettings::SettingsMap parseXmlDoc(const QDomDocument aDoc);

private:
    QSettings * mpSettings=nullptr;
    QSettings::Format mXmlFormat = QSettings::Format::InvalidFormat;
};
