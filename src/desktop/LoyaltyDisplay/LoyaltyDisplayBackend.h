#pragma once

#include <QApplication>

class QStackedLayout;

#include <VersionInfo.h>

class LoyaltyDisplayScreen;

class LoyaltyDisplayBackend : public QApplication
{
    Q_OBJECT
public: // 'tors
    LoyaltyDisplayBackend(int &argc, char **argv);
    ~LoyaltyDisplayBackend();

public slots:
    void start();
    void initialize();
    void setup();
    void run();

signals:
    void ctord();
    void started();
    void initialized();
    void setupd();
    void running();

public: // const

public: // non-const
    bool setConnections();

public: // pointers
    void screen(LoyaltyDisplayScreen * pLDS);
    LoyaltyDisplayScreen * screen();
    QStackedLayout * stack();

private:
    VersionInfo cmVersion;
    QStackedLayout * mpStack=nullptr;
    LoyaltyDisplayScreen * mpScreen=nullptr;
};




