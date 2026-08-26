#pragma once

#include <QObject>

#include "CText.h"


class ExeObject : public QObject
{
    Q_OBJECT
public: // types
    enum Type { $null = 0, Library, Console, Desktop, Android, $max };

protected: // ctors
    ExeObject(const Type aType, const CText aName);

public slots:
    virtual void initialize() {;}

signals:
    void initialized();

public: // const

public: // non-const
    virtual void registerTypes() = 0;

public: // pointers

public: // static


private:
    const Type cmType=$null;
    const CText cmName;


};
