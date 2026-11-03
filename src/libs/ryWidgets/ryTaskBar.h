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
    enum Task : SBYTE
    {
        $null       = -1,
        Gather,
        Query,
        Enroll,
        Reward,
        Alert,
        Maint,
        $max
    };
    Q_ENUM(Task);

    enum TaskFlag : BYTE
    {
        $nullFlag       = 0,
        GatherFlag      = 1 << Gather,
        QueryFlag       = 1 << Query,
        EnrollFlag      = 1 << Enroll,
        RewardFlag      = 1 << Reward,
        AlertFlag       = 1 << Alert,
        MaintFlag       = 1 << Maint,
    };
    Q_ENUM(TaskFlag);
    Q_DECLARE_FLAGS(TaskFlags, TaskFlag);

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
    Task current() const;
    TaskFlags enabled() const;

public: // non-const
    void enable(const Task aTool);
    void disable(const Task aTool);
    void enable(const TaskFlags aTools);

public: // pointer


private:
    const Size cmButtonSize=Size(60, 128);
    QVBoxLayout * mpLayout=nullptr;
    Task mCurrent=$null;
    TaskFlags mEnabled=$nullFlag;
};

inline const Size ryTaskBar::buttonSize() const { return cmButtonSize; }
inline ryTaskBar::Task ryTaskBar::current() const { return mCurrent; }
inline ryTaskBar::TaskFlags ryTaskBar::enabled() const  { return mEnabled; }
inline void ryTaskBar::enable(const Task aTool) { mEnabled.setFlag(TaskFlag(1 << aTool)); }
inline void ryTaskBar::disable(const Task aTool) { mEnabled.setFlag(TaskFlag(1 << aTool), false); }
inline void ryTaskBar::enable(const TaskFlags aTools) { mEnabled = aTools; }

Q_DECLARE_OPERATORS_FOR_FLAGS(ryTaskBar::TaskFlags);
