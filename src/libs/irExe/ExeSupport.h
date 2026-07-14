#pragma once

#include <QObject>

class KeySeg;


class CommandLine;
class Configuration;
class Options;
class Settings;

class ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(QObject *parent = nullptr);

public slots:
    void addOption(const KeySeg &aSeg);


signals:


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
};

inline CommandLine *ExeSupport::cmdl() { return mpCommandLine; }
inline Configuration *ExeSupport::cfg() { return mpConfiguration; }
inline Options *ExeSupport::opts() { return mpOptions; }
inline Settings *ExeSupport::stgs() { return mpSettings; }
