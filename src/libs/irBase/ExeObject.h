#pragma once

#include <QObject>

#include "CText.h"


class ExeObject : public QObject
{
    Q_OBJECT
public: // types
    enum Type { $null = 0, Library, Console, Desktop, Android, $max };

protected: // ctors
    explicit ExeObject(const Type aType, const CText aName);

public slots:

signals:

public: // const

public: // non-const

public: // pointers

private:
    const Type cmType=$null;
    const CText cmName;


};
