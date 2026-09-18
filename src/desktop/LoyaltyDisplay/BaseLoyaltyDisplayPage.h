#pragma once

#include <QWidget>

#include <QGridLayout>

#include <DualMap.h>
#include <KeySeg.h>
#include <LabelMap.h>
#include <Point.h>
#include <Size.h>

#include "LoyaltyDisplayScreen.h"
class BaseImageSource;
class NormalFaceLayoutWidget;

class BaseLoyaltyDisplayPage : public QWidget
{
    Q_OBJECT
public: // types

protected: // ctors
    BaseLoyaltyDisplayPage(const EightCC aECC,
                           LoyaltyDisplayScreen *parent);
    ~BaseLoyaltyDisplayPage();

public slots:
    virtual void start() {;}
    virtual void initialize();
    virtual void setup();
    virtual void run() {;}
    void add(const Index ix, NormalFaceLayoutWidget * pFaceItem);

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const
    const EightCC ecc() const;
    QString name() const;

public: // non-const
    void clearRow(const Index aRow);

public: // static

public: // pointers
    LoyaltyDisplayScreen * screen() const;
    QGridLayout * grid();
    LabelMap & labelMap();

protected:
    static const Size scmGridSize;

private:
    const EightCC cmECC;
    QGridLayout * mpGridLayout=nullptr;
    QList<Count> mRowImageCounts;
    DualMap<Point, NormalFaceLayoutWidget *>mPointItemDMap;
};

inline const EightCC BaseLoyaltyDisplayPage::ecc() const { return cmECC; }

