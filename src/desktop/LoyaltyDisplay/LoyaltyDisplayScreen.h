#pragma once

#include <QMainWindow>

class QStackedLayout;
class QThread;
class QToolBar;
class QVBoxLayout;

#include <KeyMap.h>
#include <Size.h>
class Image;

#include "ToolButtonGenerator.h"
class BaseLoyaltyDisplayPage;
class LoyaltyDisplayApplication;
class NormalFaceLayoutWidget;

class LoyaltyDisplayScreen : public QMainWindow
{
    Q_OBJECT
public: // types

public: // 'tors
    LoyaltyDisplayScreen(LoyaltyDisplayApplication *parent);
    ~LoyaltyDisplayScreen() override;

public slots:
    void start();
    void initialize();
    void setup();
    void run();
//    void startKey(const Key aKey);
  //  void show(const Key aKey, const Image &aImage);

signals:
    void started();
    void initialized();
    void setupd();
    void running();
    void newKey(const Key aKey);

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
    LoyaltyDisplayApplication * app();
    QToolBar * toolBar();
    ToolButtonGenerator * tbGen();
    BaseLoyaltyDisplayPage * page();

private: // non-const
    void addButtons();

private:
    LoyaltyDisplayApplication * mpBackend=nullptr;
    ToolButtonGenerator * mpButtonGenerator=nullptr;
    QThread * mpBackendThread=nullptr;
    Size mScreenSize=baseScreenSize();
    QToolBar * mpToolBar=nullptr;
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpPageStack=nullptr;
    EightCC mActivePage;
    QMap<EightCC, BaseLoyaltyDisplayPage *> mEccPageMap;
    KeyMapT<NormalFaceLayoutWidget *> mKeyFaceWidgetMap;
};

inline const Size LoyaltyDisplayScreen::screenSize() const { return mScreenSize; }
inline Size LoyaltyDisplayScreen::baseScreenSize() { return Size(1280, 800); }



