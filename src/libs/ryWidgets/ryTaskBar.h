#pragma once

#include <QWidget>

class QVBoxLayout;

#include <Color.h>
#include <Size.h>
#include <Types.h>

#include "ryTaskButton.h"

class ryTaskBar : public QWidget
{
    Q_OBJECT
public: // types

public: // ctors
    ryTaskBar(QWidget * parent);

public slots:
    void initialize();
    void setup();

signals:
    void initialized();
    void setuped();

public: // const
    const Size buttonSize() const;
    ryTaskButton::Task current() const;
    ryTaskButton::TaskFlags enabled() const;

public: // non-const
    void enable(const ryTaskButton::Task aTool);
    void disable(const ryTaskButton::Task aTool);
    void enable(const ryTaskButton::TaskFlags aTools);

public: // pointer


private:
    const Size cmButtonSize=Size(60, 128);
    QVBoxLayout * mpLayout=nullptr;
    ryTaskButton::List mButtonList;
    ryTaskButton::Task mCurrent=ryTaskButton::$nullTask;
    ryTaskButton::TaskFlags mEnabled=ryTaskButton::$nullFlag;
};

inline const Size ryTaskBar::buttonSize() const { return cmButtonSize; }
inline ryTaskButton::Task ryTaskBar::current() const { return mCurrent; }
inline ryTaskButton::TaskFlags ryTaskBar::enabled() const  { return mEnabled; }
inline void ryTaskBar::enable(const ryTaskButton::Task aTool) { mEnabled |= ryTaskButton::TaskFlag(1 << aTool); }
inline void ryTaskBar::disable(const ryTaskButton::Task aTool) { mEnabled &= ~ 1 << aTool; }
inline void ryTaskBar::enable(const ryTaskButton::TaskFlags aTools) { mEnabled = aTools; }

