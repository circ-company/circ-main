#pragma once

#include "FSText.h"
#include "List.h"

class FSTextList : public ListT<FSText>
{
public:
    FSTextList();
    FSTextList(const ListT<FSText> &other);
};

