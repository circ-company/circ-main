#pragma once

#include <QMetaType>

class ExeSupport;

class Configuration
{

public: // types

public: // ctors
    Configuration(ExeSupport * pExe);

public: // const

public: // non-const

public: // pointers
    ExeSupport * exe();

public: // debug

private:
    ExeSupport * mpExeSupport=nullptr;

public: // QMetaType
    Configuration() = default;
    ~Configuration() = default;
    Configuration(const Configuration &) = default;
    Configuration &operator=(const Configuration &) = default;
    Configuration & it() { return *this; }
    const Configuration & it() const { return *this; }
};

Q_DECLARE_METATYPE(Configuration);

inline ExeSupport *Configuration::exe() { Q_CHECK_PTR(mpExeSupport);  return mpExeSupport; }





