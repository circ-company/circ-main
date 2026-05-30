#pragma once

#include <Url.h>

class OutputInterface
{
public:
    OutputInterface() = default;
    virtual bool open(const Url &logOutUrl) = 0;
};
