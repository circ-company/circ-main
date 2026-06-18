#pragma once

#include <QAction>

#include <AText.h>
#include <Id.h>
#include <Key.h>

class Action
{
protected: // NULL ctor
    explicit Action();
public: // ctors
    explicit Action(const AText &key);

public: // const

public: // non-const
    void set(const AText &key);

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
