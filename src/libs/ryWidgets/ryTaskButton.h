#pragma once

#include <QToolButton>

#include <QList>
#include <QString>
class QAction;

#include <CText.h>
#include <Color.h>

class ryTaskBar;

class ryTaskButton : public QToolButton
{
    Q_OBJECT
public: // types
    enum State
    {
        $nullState       = 0,
        Enabled     = 0x01,
        Down        = 0x02,
        Checkable   = 0x04,
        Checked     = 0x08,
        ShowText    = 0x10,
        ShowIcon    = 0x20,
        Radio       = 0x40,
    };
    Q_ENUM(State);
    enum Task : SBYTE
    {
        $nullTask       = -1,
        Gather,
        Query,
        Enroll,
        Reward,
        Alert,
        Maint,
        $maxTask
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

    typedef QList<ryTaskButton *> List;

public: // ctors
    explicit ryTaskButton(ryTaskBar *parent);
    ryTaskButton(const Task aTask, const Color aBaseColor, ryTaskBar *parent);

public slots:

signals:

public: // const
    Task task() const;
    CText name() const;
    bool isEnabled() const;
    bool isDisabled() const;
    Color baseColor() const;
    Color mainColor() const;
    Color borderColor() const;
    Color textColor() const;

public: // non-const
    void setUserText(const QString aEnglishText);
    virtual void paintEvent(QPaintEvent *event) override;

public: // pointer
    ryTaskBar * bar();


public: // static

private:
    const Task cmTask=$nullTask;
    CText mName;
    ryTaskBar * mpBar=nullptr;
    QAction * mpAction=nullptr;
    State mState=$nullState;
    QString mUserText;
    Color mBaseColor;
};

inline CText ryTaskButton::name() const { return mName; }
inline bool ryTaskButton::isEnabled() const { return mState & Enabled; }
inline bool ryTaskButton::isDisabled() const { return ! isEnabled(); }
inline ryTaskBar *ryTaskButton::bar() { Q_CHECK_PTR(mpBar); return mpBar; }


