#pragma once

#include <Url.h>

class LogOutputInterface
{
public: // ctor
    LogOutputInterface();
    LogOutputInterface(const Url &url);

public: // const
    bool isOpen() const;
    Url::Type type() const;

public: // npn-const
    void set(const Url &url);
    bool open(const Url &url);
    bool open();
    void close();

private:
    Url mUrl;
};
