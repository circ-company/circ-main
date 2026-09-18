#pragma once

#include <QMainWindow>

class QStackedLayout;
class QThread;
class QToolBar;
class QVBoxLayout;

#include <KeyMap.h>
#include <Size.h>

#include "ToolButtonGenerator.h"
class BaseLoyaltyDisplayPage;
class LoyaltyDisplayBackend;
class NormalFaceLayoutWidget;

class LoyaltyDisplayScreen : public QMainWindow
{
    Q_OBJECT
public: // types

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
    void setupToolGallery();
    void addPage(BaseLoyaltyDisplayPage * pPage);

public: // static
    static Size baseScreenSize();
    static Size buttonSize();
    static Size buttonLayout();
    static Size faceSize();
    static Size faceLayout();

public: // pointers
    LoyaltyDisplayBackend * backend();
    QToolBar * toolBar();
    ToolButtonGenerator * tbGen();

private: // non-const
    void addButtons();

private:
    LoyaltyDisplayBackend * mpBackend=nullptr;
    ToolButtonGenerator * mpButtonGenerator=nullptr;
    QThread * mpBackendThread=nullptr;
    Size mScreenSize=baseScreenSize();
    QToolBar * mpToolBar=nullptr;
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpPageStack=nullptr;
    QMap<EightCC, BaseLoyaltyDisplayPage *> mEccPageMap;
    KeyMapT<NormalFaceLayoutWidget *> mKeyFaceWidgetMap;
};

inline const Size LoyaltyDisplayScreen::screenSize() const { return mScreenSize; }
inline Size LoyaltyDisplayScreen::baseScreenSize() { return Size(1280, 800); }



