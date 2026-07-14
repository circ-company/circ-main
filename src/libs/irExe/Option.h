#pragma once

#include <QCommandLineOption>

#include <QChar>
#include <QList>
#include <QMetaType>

#include <KeySeg.h>
#include <KeySegList.h>

class Options;

class Option : public QCommandLineOption
{
public: // types

private: // ctors
    friend class Options;
    Option(Options * mpOpts, const KeySeg &aName);
    Option(Options * mpOpts, const KeySeg &aName, const QChar &aChar);
    Option(Options * mpOpts, const KeySeg &aName, const KeySegList &aExtras);
    Option(Options * mpOpts, const KeySeg &aName, const KeySegList &aExtras, const QChar &aChar);


public: // const

public: // non-const

public: // pointers
    Options * opts();


public: // debug

private:
    Options * mpOptions=nullptr;

public: // QMetaType
    Option() = delete;
    ~Option() = default;
    Option(const Option &) = default;
    Option &operator=(const Option &) = default;
    Option & it() { return *this; }
    const Option & it() const { return *this; }
};

Q_DECLARE_METATYPE(Option);



