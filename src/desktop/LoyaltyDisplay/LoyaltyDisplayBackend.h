#pragma once

#include <QApplication>

#include <QDir>
#include <QList>
class QStackedLayout;

#include <KeyMap.h>
#include <Url.h>
#include <VersionInfo.h>
class Key;

class BaseImageSource;
class LoyaltyDisplayScreen;
class NormalFaceLayoutWidget;

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
    void process(BaseImageSource * pSource);

signals:
    void ctord();
    void started();
    void initialized();
    void setupd();
    void running();
    void processing(const Key &key);
    void addFace(const Index ix, NormalFaceLayoutWidget * pFaceItem);

public: // const

public: // non-const
    QDir takeDir();

public: // pointers
    void screen(LoyaltyDisplayScreen * pLDS);
    LoyaltyDisplayScreen * screen();
    QStackedLayout * stack();

private: // non-const
    bool setConnections();

private:
    VersionInfo cmVersion;
    LoyaltyDisplayScreen * mpScreen=nullptr;
    QList<QDir> mDirArguments;
    KeyMapT<BaseImageSource *> mArgKeySourceMap;
};




