#pragma once

#include "CodeArgument.h"

#include "Types.h"

class CodeArgumentList : public CodeArgument::List
{
public: // ctors
    CodeArgumentList();

public: // const
    bool isValid(const Index ix) const;

public: // non-const

};
