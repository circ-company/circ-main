#pragma once

#include <QMetaType>

class ExeSupport;

class Settings
{

public: // types

public: // ctors
    Settings(ExeSupport * pExe);

public: // const

public: // non-const

public: // pointers
    ExeSupport * exe();


public: // debug

private:
    ExeSupport * mpExeSupport=nullptr;

public: // QMetaType
    Settings() = default;
    ~Settings() = default;
    Settings(const Settings &) = default;
    Settings &operator=(const Settings &) = default;
    Settings & it() { return *this; }
    const Settings & it() const { return *this; }
};

Q_DECLARE_METATYPE(Settings);

inline ExeSupport *Settings::exe() { Q_CHECK_PTR(mpExeSupport);  return mpExeSupport; }





