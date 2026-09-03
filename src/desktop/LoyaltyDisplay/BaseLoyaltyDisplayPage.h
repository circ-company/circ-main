#pragma once

#include <QWidget>

#include <QGridLayout>

#include <DualMap.h>
#include <KeySeg.h>
#include <LabelMap.h>
#include <Point.h>
#include <Size.h>

#include "LoyaltyDisplayScreen.h"
class NormalFaceLayoutWidget;

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
    virtual KeySeg key() const;
    virtual QString name() const = 0;

public: // non-const

public: // static

public: // pointers
    LoyaltyDisplayScreen * screen() const;
    QGridLayout * grid();
    LabelMap & labelMap();

protected:
    static const Size scmGridSize;

private:
    const LoyaltyDisplayScreen::PageType cmType;
    const KeySeg cmKeySeg;
    QGridLayout * mpGridLayout=nullptr;
    QList<Count> mRowImageCounts;
    DualMap<Point, NormalFaceLayoutWidget *>mPointItemDMap;
};

inline LoyaltyDisplayScreen::PageType BaseLoyaltyDisplayPage::type() const { return cmType; }
