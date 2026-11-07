#pragma once

#include <QToolButton>

#include <QList>

#include <Color.h>

class ryTaskBar;

class ryTaskButton : public QToolButton
{
    Q_OBJECT
public: // types
    enum State
    {
        $null       = 0,
        Enabled     = 0x01,
        Down        = 0x02,
        Checkable   = 0x04,
        Checked     = 0x08,
        ShowText    = 0x10,
        ShowIcon    = 0x20,
        Radio       = 0x40,
    };
    Q_ENUM(State);
    Q_DECLARE_FLAGS(States, State);
    typedef QList<ryTaskButton *> List;

public: // ctors
    explicit ryTaskButton(ryTaskBar *parent);
    ryTaskButton(const QString &aText, const Color aBaseColor, ryTaskBar *parent);

public slots:

signals:

public: // const
    Color baseColor();
    Color mainColor();
    Color borderColor();
    Color textColor();

public: // non-const
    virtual void paintEvent(QPaintEvent *event) override;

public: // pointer
    ryTaskBar * bar();


public: // static

private:
    ryTaskBar * mpBar=nullptr;
    States mStates=$null;
    QString mText;
    Color mBaseColor;
};

inline Color ryTaskButton::baseColor() { return mBaseColor; }
inline ryTaskBar *ryTaskButton::bar() { Q_CHECK_PTR(mpBar); return mpBar; }

Q_DECLARE_OPERATORS_FOR_FLAGS(ryTaskButton::States);

