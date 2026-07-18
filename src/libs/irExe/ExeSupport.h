#pragma once

#include <QObject>

class KeySeg;

#include <VersionInfo.h>
class CommandLine;
class Configuration;
class Option;
class Options;
class Settings;

class ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(const QString &aAppName, QObject *parent = nullptr);

public slots:

signals:

public: // const
    VersionInfo ver() const;

public: // pointers
    CommandLine * cmdl();
    Configuration * cfg();
    Options * opts();
    Settings * stgs();

private:
    CommandLine * mpCommandLine=nullptr;
    Configuration * mpConfiguration=nullptr;
    Options * mpOptions=nullptr;
    Settings * mpSettings=nullptr;
    VersionInfo mVersionInfo;
};

inline VersionInfo ExeSupport::ver() const { return mVersionInfo; }
inline CommandLine *ExeSupport::cmdl() { return mpCommandLine; }
inline Configuration *ExeSupport::cfg() { return mpConfiguration; }
inline Options *ExeSupport::opts() { return mpOptions; }
inline Settings *ExeSupport::stgs() { return mpSettings; }
