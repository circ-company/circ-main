#include "Id.h"

#include <MillisecondTime.h>
#include <Uid.h>


DEFINE_DATAPROPS(Id, IdData);

QWORD Id::smCtorSeq = 0;

Id::Id(const bool nilUid) : data(new IdData) { uid(nilUid); ctor(); }
Id::Id(const Uid::Version ver) : data(new IdData) { uid(ver); ctor(); }
Id::Id(const Uid &u) : data(new IdData) { uid(u); ctor(); }
Id::Id(const Uid &u, const IdNo i)  : data(new IdData) { set(u, i); ctor(); }
Id::Id(const Uid &u, const Key &k) : data(new IdData) { set(u, k); ctor(); }
Id::Id(const Uid &u, const QString &n) : data(new IdData) { set(u, n); ctor(); }
Id::Id(const IdNo i) : data(new IdData) { idno(i); ctor(); }
Id::Id(const Key &k) : data(new IdData) { key(k); ctor(); }
Id::Id(const QString &n) : data(new IdData) { name(n); ctor(); }
Id::Id(const Uid &u, const IdNo i, const Key &k, const QString &n)
    : data(new IdData) { uid(u); idno(i); key(k); name(n); ctor(); }
void Id::ctor(void) { ctorEms(MillisecondTime::current()); ctorSeq(++smCtorSeq); }
void Id::dtor(void) {;}

bool Id::isNull() const
{
    return uid().isNull();
}

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

