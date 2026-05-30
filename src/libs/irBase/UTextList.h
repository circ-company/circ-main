#pragma once

#include <UText.h>

#include <QMetaType>

class UTextList : public UText::List
{
public: // ctors
    UTextList(const QStringList &qsl);

public: // const

public: // non-const
    void set(const QStringList &qsl);

public: // pointers
    const UTextList & it() const { return *this; }
    UTextList & it() { return *this; }

public: // QMetaType
    UTextList() = default;
    ~UTextList() = default;
    UTextList(const UTextList &) = default;
    UTextList &operator=(const UTextList &) = default;
};

Q_DECLARE_METATYPE(UTextList);
