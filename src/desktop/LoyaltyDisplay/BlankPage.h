#pragma once

#include <QWidget>

class QPaintEvent;

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
    //virtual void initialize();
    virtual void setup() final;
    //virtual void run();

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const

public: // non-const
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public: // pointers

private: // non-const
    void setupButtonBar();

private:
    PaintModes mPaintModes=$null;

};
