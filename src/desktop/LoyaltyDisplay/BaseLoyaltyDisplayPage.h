#pragma once

#include <QWidget>

#include <QGridLayout>

#include <KeySeg.h>
#include <LabelMap.h>
#include <Size.h>

#include "LoyaltyDisplayScreen.h"

class BaseLoyaltyDisplayPage : public QWidget
{
    Q_OBJECT

protected: // ctors
    BaseLoyaltyDisplayPage(const LoyaltyDisplayScreen::PageType aType,
                           LoyaltyDisplayScreen *parent);
    ~BaseLoyaltyDisplayPage();

public slots:
    virtual void start() {;}
    virtual void initialize();
    virtual void setup() = 0;
    virtual void run() {;}

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const
    virtual LoyaltyDisplayScreen::PageType type() const;
    KeySeg key() const;
    virtual Size size() const;

public: // non-const

public: // pointers
    LoyaltyDisplayScreen * screen() const;
    QGridLayout * gridLayout();
    LabelMap & labelMap();

private:
    Size mScreenSize;
    const LoyaltyDisplayScreen::PageType cmType;
    QGridLayout * mpGridLayout=nullptr;
    LabelMap mKeyLabelMap;

};

inline LoyaltyDisplayScreen::PageType BaseLoyaltyDisplayPage::type() const { return cmType; }
inline Size BaseLoyaltyDisplayPage::size() const { return screen()->screenSize(); }
inline LabelMap &BaseLoyaltyDisplayPage::labelMap() { return mKeyLabelMap; }
