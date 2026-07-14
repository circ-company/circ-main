#pragma once

#include <QMetaType>

class ExeSupport;

class CommandLine
{
public: // types

public: // ctors
    CommandLine(ExeSupport * pExe);

public: // const

public: // non-const

public: // pointers
    ExeSupport * exe();

public: // debug

private:
    ExeSupport * mpExeSupport=nullptr;

public: // QMetaType
    CommandLine() = default;
    ~CommandLine() = default;
    CommandLine(const CommandLine &) = default;
    CommandLine &operator=(const CommandLine &) = default;
    CommandLine & it() { return *this; }
    const CommandLine & it() const { return *this; }
};

Q_DECLARE_METATYPE(CommandLine);

inline ExeSupport *CommandLine::exe() { Q_CHECK_PTR(mpExeSupport);  return mpExeSupport; }


