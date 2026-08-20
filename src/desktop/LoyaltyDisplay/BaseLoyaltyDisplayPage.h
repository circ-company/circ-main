#pragma once

#include <QWidget>

#include <Key.h>
#include <Size.h>

class LoyaltyDisplayScreen;

class BaseLoyaltyDisplayPage : public QWidget
{
    Q_OBJECT
protected: // ctors
    BaseLoyaltyDisplayPage(const Key aKey, LoyaltyDisplayScreen *parent);


public slots:
    virtual void start() {;}
    virtual void initialize() {;}
    virtual void setup() = 0;
    virtual void run() {;}

signals:
    void started();
    void initialized();
    void setupd();
    void running();

public: // const
    Key key() const;
    Size screenSize() const;

public: // non-const
    void screenSize(const Size aSz);

public: // pointers
    LoyaltyDisplayScreen * screen();

private:
    const Key cmKey;
    Size mScreenSize;

};

inline Key BaseLoyaltyDisplayPage::key() const { return cmKey; }
inline Size BaseLoyaltyDisplayPage::screenSize() const  { return mScreenSize; }
