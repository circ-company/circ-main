#pragma once

#include "StatusCodeArgument.h"

#include "Types.h"

class StatusCodeArgumentList : public StatusCodeArgument::List
{
public: // ctors
    StatusCodeArgumentList();

public: // const
    bool isValid(const Index ix) const;

public: // non-const

};
