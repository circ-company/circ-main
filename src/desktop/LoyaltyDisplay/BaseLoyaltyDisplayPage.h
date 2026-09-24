#pragma once

#include <QWidget>

#include <QGridLayout>
#include <QPoint>

#include <DualMap.h>
#include <KeySeg.h>
#include <LabelMap.h>
#include <Point.h>
#include <Size.h>
class Image;

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
    virtual void startKey(const Key aKey);
    virtual void showImage(const Key aKey, const Image &aImage);
    void add(const Index ix, NormalFaceLayoutWidget * pFaceItem);

signals:
    void started();
    void initialized();
    void setupd();
    void running();
    void imageShown();

public: // const
    const EightCC ecc() const;
    QString name() const;

public: // non-const
    void clearRow(const Index aRow);
    Index clearOldestRow();

public: // static

public: // pointers
    LoyaltyDisplayScreen * screen() const;
    QGridLayout * grid();
    LabelMap & labelMap();

protected:
    static const Size scmGridSize;

protected:
    const EightCC cmECC;
    QGridLayout * mpGridLayout=nullptr;
    Index mCurrentRow=0;
    DualMap<Index, Key> mRowKeyDMap;
    QList<Count> mRowImageCounts;
    DualMap<Index, NormalFaceLayoutWidget *>mPointIxItemDMap;
    QMap<Milliseconds, Index> mOldestRowMap;
};

inline const EightCC BaseLoyaltyDisplayPage::ecc() const { return cmECC; }

