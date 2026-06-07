#pragma once

#include <QtLogging>
#include <QByteArray>
#include <QList>
#include <QMetaType>
#include <QString>
#include <QVariantList>

#include <cstdio>

#include "Types.h"

class AText : public QByteArray
{
public: // types
    typedef QList<AText> List;
    typedef QPair<AText, AText>  Pair;
    enum Clean
    {
        $nullClean = 0, All, TrimL, TrimR, Trim, Simplify, $maxClean
    };
    enum Modify
    {
        $nullModify = 0, Upper, Lower, CaseFold,  Local8, Utf8, Latin1, $maxModify
    };

public: // ctors
    AText(const char * pch);
    AText(const char * pch, const QChar repl);
    AText(const char ch);
    AText(const QByteArray &ba);
    AText(const QByteArray &ba, const QChar repl);
    AText(const QString &s);
    AText(const Count k, const char ch=' ');
    AText(const unsigned u, const BYTE base=10);

public: // const
    bool isEmpty() const;
    bool isValid(const Index ix);
    AText formatted(const QVariantList vars);
    AText modified(const Modify mod) const;
    Pair keyValue(const char ch) const;
    AText sub(const IndexList ixs);
    QString toString() const;
    operator QString() const;
    QString operator () () const;
    QByteArrayView toQBAV() const;
    bool equals(const AText &rhs) const;
    bool like(const AText &rhs, const Modify mod) const;
    bool less(const AText &rhs) const;
    bool operator == (const AText &rhs);
    bool operator < (const AText &rhs);

public: // non-const
    void set(const char ch);
    void set(const char * pch);
    void set(const QByteArray &ba);
    void set(const char *pch, const QChar repl);
    void set(const QString &s);
    void set(const QByteArrayList &ba);
    void set(const QStringList &s);
    void set(const Count k, const char ch=' ');
    void set(const unsigned u, const BYTE base=10);
    void set(const Modify mod);
    int vprintf(const char * format, va_list vlist);
    void setList(const char * pch);
    void setList(const QByteArray &ba);
    void setList(const QString &s);
    AText append(const AText &more);
    AText append(const char ch);
    AText takeFirst(const Count k);
    void removeFirst(const Count k);
    void removeEach(const char ch);
    void removeEach(const AText &atx);
    AText operator += (const AText &more);
    AText operator += (const char ch);

public: // pointers
    AText it() const;
    AText & it();

public: // static
    static char hinge();
    static void hinge(const char ch);

protected: // virtual const
    virtual bool isValidFirst(const char ch) const;
    virtual bool isValidChar(const char ch) const;

private:
    static QString saveVarListString(const QVariantList &vars, const Index ix);
    static char smHingeChar;

public: // QMetaType
    AText() = default;
    ~AText() = default;
    AText(const AText &) = default;
    AText &operator=(const AText &) = default;
};

extern AText operator + (const AText &lhs, const AText &rhs);

Q_DECLARE_METATYPE(AText);

inline QString AText::toString() const { return QString(constData()); }
inline AText::operator QString () const { return toString(); }
inline QString AText::operator () () const { return toString(); }

inline QByteArrayView AText::toQBAV() const { return QByteArrayView(it()); }
inline bool AText::operator ==(const AText &rhs) { return equals(rhs); }
inline bool AText::operator <(const AText &rhs) { return less(rhs); }
inline void AText::set(const QByteArray &ba) { set(ba.constData()); }
inline void AText::set(const QString &s)  { set(s.toLocal8Bit()); }
inline AText AText::operator +=(const AText &more) { return append(more); }
inline AText AText::operator +=(const char ch) { return append(ch); }
inline AText AText::it() const { return *this; }
inline AText &AText::it() { return *this; }
inline char AText::hinge() { return smHingeChar; }

