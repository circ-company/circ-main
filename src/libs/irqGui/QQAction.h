#pragma once

#include <QAction>

#include <Id.h>
#include <Key.h>

#include "ActionManager.h"

class QQAction
{
protected: // NULL ctor
    explicit QQAction();
public: // ctors
    explicit QQAction(const Key &key);

public: // const

public: // non-const
    void set(const Key &key);

public: // pointer
    Id & id();
    Id & id() const;

public: // static
    static QString ampify(const Key &key);

protected:

private:
    Id mId;
    QAction * mpAction=nullptr;
};
