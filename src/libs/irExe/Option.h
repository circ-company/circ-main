#pragma once

#include <QCommandLineOption>

#include <QChar>
#include <QList>
#include <QMetaType>
#include <QString>
#include <QStringList>

#include <KeySeg.h>
#include <KeySegList.h>

class Options;

class Option
{
public: // types

public: // ctors
    Option(Options * mpOpts, const KeySeg &aName);
    Option(Options * mpOpts, const KeySeg &aName, const QChar &aChar);
    Option(Options * mpOpts, const KeySeg &aName, const KeySegList &aExtras);
    Option(Options * mpOpts, const KeySeg &aName,
           const KeySegList &aExtras, const QChar &aChar);

public: // const
    KeySeg name() const;
    QString value() const;

public: // non-const
    void description(const QString &aDesc);
    void valueName(const QString &aValName);
    void valueDefault(const QString &aDefVal);
    void valueDefaults(const QStringList &aDefVals);
    void flags(const QCommandLineOption::Flags aFlags);
    void generate();

public: // pointers
    Options * opts();

public: // debug
    QString toDebugString() const;

private:
    Options * mpOptions=nullptr;
    QCommandLineOption mCLOption;
    QCommandLineOption::Flags mFlags = QCommandLineOption::Flags(0);
    QString mValue;
    KeySeg mName;
    KeySegList mExtraNames;
    QChar mChar;
    QString mDescription;
    QString mValueName;
    QStringList mValueDefaults;

public: // QMetaType
    Option() = delete;
    ~Option() = default;
    Option(const Option &) = default;
    Option &operator=(const Option &) = default;
    Option & it() { return *this; }
    const Option & it() const { return *this; }
};

Q_DECLARE_METATYPE(Option);

inline KeySeg Option::name() const { return mName; }
inline void Option::description(const QString &aDesc) { mDescription = aDesc; }
inline void Option::valueName(const QString &aValName) { mValueName = aValName; }
inline void Option::valueDefaults(const QStringList &aDefVals) { mValueDefaults = aDefVals; }





