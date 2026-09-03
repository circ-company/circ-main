#pragma once

#include <QMainWindow>

class QStackedLayout;
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
        $null = -1,
        Home,
        Capture,
        Page2,
        Page3,
        Page4,
        Page5,
        Page6,
        Page7,
        Page8,
        Page9,
        Finish,
        System,
        $Count
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
    const Size screenSize() const;

public: // non-const
    void screenSize(const Size aSz);
    void setupButtonBar();
    void addPage(BaseLoyaltyDisplayPage * pPage);

public: // static
    static Size baseScreenSize();
    static KeySeg key(const PageType aType);

public: // pointers
    LoyaltyDisplayBackend * backend();

private:
    LoyaltyDisplayBackend * mpBackend=nullptr;
    QThread * mpBackendThread=nullptr;
    Size mScreenSize=baseScreenSize();
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpMainStack=nullptr;
    QToolBar * mpToolBar=nullptr;
    KeyMapT<BaseLoyaltyDisplayPage *> mKeyPageMap;
};

inline const Size LoyaltyDisplayScreen::screenSize() const { return mScreenSize; }
inline Size LoyaltyDisplayScreen::baseScreenSize() { return Size(1280, 800); }


