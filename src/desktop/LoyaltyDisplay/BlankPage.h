#pragma once

#include <QWidget>

#include <QList>

class QPaintEvent;

#include <Size.h>
#include <Types.h>

#include "BaseLoyaltyDisplayPage.h"

class BlankPage : public BaseLoyaltyDisplayPage
{
    Q_OBJECT
public: // types
    enum PaintMode
    {
        $null = 0,
        Background,
    };
    Q_ENUM(PaintMode);
    Q_DECLARE_FLAGS(PaintModes, PaintMode);

public:
    BlankPage(LoyaltyDisplayScreen *parent);
    ~BlankPage();

public slots:
    //virtual void start();
    //virtual void initialize() final;
    virtual void setup() final;
    //virtual void run();
    void add(const Index aRow, const QImage aImage);

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const

public: // non-const
    virtual KeySeg key() const final;
    virtual QString name() const final;
    virtual void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public: // pointers

private: // non-const

private:
    PaintModes mPaintModes=$null;
};
