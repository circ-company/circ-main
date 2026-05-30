#pragma once

#include "CodeValue.h"

#include "Types.h"

class CodeValueList : public CodeValue::List
{
public: // ctors
    CodeValueList();

public: // const
    bool isValid(const Index ix) const;

public: // non-const
    void set(const Index ix, const CodeValue &cv);

};
