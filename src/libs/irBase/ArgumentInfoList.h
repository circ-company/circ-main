#pragma once

#include "ArgumentInfo.h"

#include <QVariantList>
#include <QMetaType>

#include "ArgumentInfo.h"


class ArgumentInfoList : public ArgumentInfo::List
{
public: // types

public: // ctors

public: // const
//    Count count() const;
    QVariantList values() const;

public: // non-const
  //  void set(const Index ix, const ArgumentInfo &aInfo);

public: // pointers

private:

public: // QMetaType
    ArgumentInfoList() = default;
    ~ArgumentInfoList() = default;
    ArgumentInfoList(const ArgumentInfoList &) = default;
    ArgumentInfoList &operator=(const ArgumentInfoList &) = default;
    ArgumentInfoList & it() { return *this; }
    const ArgumentInfoList & it() const { return *this; }
};

Q_DECLARE_METATYPE(ArgumentInfoList);
