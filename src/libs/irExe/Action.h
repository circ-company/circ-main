#pragma once

#include <QAction>

#include <AText.h>
#include <Id.h>
#include <Key.h>
#include <Log.h>

class Action
{
protected: // NULL ctor
    explicit Action();
public: // ctors
    Action(const AText &key);

public: // const

public: // non-const
    void set(const AText &aKey, const QString &aName=QString());

public: // pointer
    Id & id();
    const Id id() const;
    QAction * qaction();
    QAction * operator () ();

    QString toDebugString() const;

public: // static
    static QString unampify(const Key &key);

protected:

private:
    Id mId;
    QAction * mpAction=nullptr;
};

inline Id &Action::id() { return mId; }
inline const Id Action::id() const { return mId; }
inline QAction *Action::qaction() { MASSERT(mpAction); return mpAction; }
inline QAction *Action::operator ()() { return qaction(); }
