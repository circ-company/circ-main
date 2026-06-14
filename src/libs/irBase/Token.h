#pragma once

#include <QObject>
#include <QList>
#include <QPair>
#include <QObject>

#include "AText.h"
#include "CharType.h"

class Token : public QObject
{
    Q_GADGET
public: // types
    typedef QPair<CharType::Flags, AText> Pair;
    typedef QList<Pair> List;

public: // ctors

public: // const

public: // non-const

public: // pointers

private:

};
