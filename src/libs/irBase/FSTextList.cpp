#include "FSTextList.h"

FSTextList::FSTextList() {;}

FSTextList::FSTextList(const ListT<FSText> &other)
{
    *this = other;
}
