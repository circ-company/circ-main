#include "Id.h"

#include <MillisecondTime.h>
#include <Uid.h>


DEFINE_DATAPROPS(Id, IdData);

QWORD Id::smCtorSeq = 0;

Id::Id(const bool nilUid) : data(new IdData) { uid(nilUid); ctor(); }
Id::Id(const Uid &u, const IdNo i)  : data(new IdData) { set(u, i); ctor(); }
Id::Id(const Uid &u, const Key &k) : data(new IdData) { set(u, k); ctor(); }
Id::Id(const Uid &u, const QString &n) : data(new IdData) { set(u, n); ctor(); }
Id::Id(const IdNo i) : data(new IdData) { uid(false); idno(i); ctor(); }
Id::Id(const Key &k) : data(new IdData) { uid(false); key(k); ctor(); set(Uid::VerTextSha); }
Id::Id(const QString &n) : data(new IdData) { uid(false); name(n); ctor(); }
Id::Id(const Uid &u, const IdNo i, const Key &k, const QString &n)
    : data(new IdData) { uid(u); idno(i); key(k); name(n); ctor(); }

void Id::ctor(void)
{
    ctorEms(MillisecondTime::current());
    if (0 == smCtorSeq) ctorEms(ctorEms() + 1);
    ctorSeq(++smCtorSeq);
    if (uid().isNull() || uid().isNil())
    {
        if (idno())
            uid(Uid(0xA55AA55AA55AA55AUL ^ idno(), idno()));
        else if ( ! key().isEmpty())
            uid(key().toUid());
        else if ( ! name().isEmpty())
            uid(Uid(Uid::VerTextSha, name()));
    }
    if (0UL == idno())
    {
        if  ( ! uid().isNull() && ! uid().isNil())
            idno(uid().hi() ^ uid().lo());
        else if ( ! key().isNull() && ! key().isEmpty())
            idno(key().hash64());
        if ( ! name().isEmpty())
        {
            Uid tNameUid(Uid::VerTextSha, name());
            idno(tNameUid.hi() ^ tNameUid.lo());
        }
    }
    if (key().isEmpty() || key().isNull())
    {
        if ( ! name().isEmpty())
            key(Key::fromName(name()));
        else if ( ! uid().isNull() && ! uid().isNil())
            key(uid().toKey());
        else if (0UL != idno())
            key(idno());
    }
    if (name().isEmpty())
    {
        if ( ! key().isEmpty())
            name(key().toString());
        else if (idno())
            name(QString::number(idno(), 10));
        else if ( !! uid().isNil() && ! uid().isNull())
            name(uid().toString());
    }
}

void Id::dtor(void) {;}



QString Id::toString() const
{
    QString result;
    if ( ! key().isNull())
        result = key().toString();
    else if ( ! name().isEmpty())
        result = name().simplified().replace(' ', '-');
    else if (0 != idno())
        result = QString::number(idno());
    else if ( ! uid().isNull())
        result = uid().tail();
    else
        result = "{null}";
    return result;
}

void Id::set(const Uid::Version ver)
{
    switch (ver)
    {
    case Uid::VerTextMd5:
    case Uid::VerTextSha:
        uid(Uid(ver, key().toString()));
        idno(uid().lo() ^ uid().hi());
        break;
    default:
        // unhandled
        break;
    }
}

QDebug operator << (QDebug debug, const Id &ident)
{
    debug << "{Ident:" << ident.uid().tail() << ident.idno()
          << ident.key().toString() << ident.name() << "}";
    return debug;
}


void Id::set(const Uid &u, const IdNo i) { uid(u), idno(i); }

void Id::set(const Uid &u, const Key &k) { uid(u), key(k); }

void Id::set(const Uid &u, const QString &n) { uid(u), name(n); }

void Id::set(const Uid &u, const IdNo i, const Key &k, const QString &n)
{ uid(u), idno(i), key(k), name(n); }
