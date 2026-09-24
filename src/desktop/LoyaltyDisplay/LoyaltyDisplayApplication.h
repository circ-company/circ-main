#pragma once

#include <QApplication>

#include <QDir>
#include <QList>
class QStackedLayout;
class QTimer;

#include <KeyMap.h>
#include <Id.h>
#include <Url.h>
#include <VersionInfo.h>
class Key;
class Image;

class BaseImageSource;
class LoyaltyDisplayScreen;
class NormalFaceLayoutWidget;

class LoyaltyDisplayApplication : public QApplication
{
    Q_OBJECT
public: // 'tors
    LoyaltyDisplayApplication(int &argc, char **argv);
    ~LoyaltyDisplayApplication();

public slots:
    void start();
    void initialize();
    void setup();
    void go();
    void showNext();
    void process(BaseImageSource * pSource);

signals:
    void ctord();
    void started();
    void initialized();
    void setupd();
    void going();
    void newKey(const Key aKey);
    void showImage(const Key aKey, const Image &aImage);
    void showingImage();
    void processing(const Key &key);

public: // const
    QList<BaseImageSource *> sourceList() const;

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
    QStringList mArguments;
    KeyMapT<QDir> mKeyDirMap;
    KeyMapT<BaseImageSource *> mDirKeySourceMap;
};




