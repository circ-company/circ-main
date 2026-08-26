#pragma once

#include <QMainWindow>

class QTabWidget;
class QThread;

#include <KeyMap.h>
#include <Size.h>

class BaseLoyaltyDisplayPage;
class LoyaltyDisplayBackend;

class LoyaltyDisplayScreen : public QMainWindow
{
    Q_OBJECT
public: // types
    enum PageType
    {
        $null = 0,
        Blank,
    };
    Q_ENUM(PageType);

public: // 'tors
    LoyaltyDisplayScreen(LoyaltyDisplayBackend *parent);
    ~LoyaltyDisplayScreen() override;

public slots:
    void start();
    void initialize();
    void setup();
    void run();

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const
    bool isRunning() const;
    Size screenSize() const;

public: // non-const
    void screenSize(const Size aSz);
    void addPage(BaseLoyaltyDisplayPage * pPage);

public: // static
    static Size baseScreenSize();
    static KeySeg key(const PageType aType);

public: // pointers
    LoyaltyDisplayBackend * backend();

private:
    LoyaltyDisplayBackend * mpBackend=nullptr;
    QThread * mpBackendThread=nullptr;
    bool mIsRunning = false;
    Size mScreenSize=baseScreenSize();
    QTabWidget * mpMainWidget=nullptr;
    KeyMapT<BaseLoyaltyDisplayPage *> mKeyPageMap;
};

inline bool LoyaltyDisplayScreen::isRunning() const { return mIsRunning; }
inline Size LoyaltyDisplayScreen::screenSize() const { return mScreenSize; }
inline Size LoyaltyDisplayScreen::baseScreenSize() { return Size(1280, 800); }


