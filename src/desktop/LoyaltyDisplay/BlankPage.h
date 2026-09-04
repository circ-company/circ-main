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

public:
    BlankPage(LoyaltyDisplayScreen *parent);
    ~BlankPage();

public slots:
    virtual void setup() final;

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const

public: // non-const
    virtual KeySeg key() const final;
    virtual QString name() const final;

public: // pointers

private: // non-const

private:
};
