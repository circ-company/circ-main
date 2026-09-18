//!file {Eclipse7}/libs/eirCore/Types.h Common typedef's
#pragma once

#include <QtGlobal>
#include <QList>
#include <QString>
#include <QUuid>

typedef quint8          BYTE;
typedef quint16         WORD;
typedef float           WORDF;
typedef quint32         DWORD;
typedef double          DWORDF;
typedef quint64         QWORD;
#ifndef Q_CC_MSVC
typedef quint128        OWORD; // octo
//#define SEWORD          unsigned _BitInt(256)
#endif

typedef qint16          SWORD;
typedef qint32          SDWORD;
typedef qint64          SQWORD;
#ifndef Q_CC_MSVC
typedef qint128         SOWORD;
//#define SSEWORD         signed _BitInt(256)
#endif

typedef quintptr        NWORD;  // N=Native
typedef qptrdiff        SNWORD;
typedef signed          INT;
typedef signed          SINT;
typedef unsigned        UINT;
typedef double          FLOAT;

typedef QUuid::Id128Bytes UID;
typedef QWORD           Milliseconds;
typedef qsizetype       Index;  // signed
typedef size_t          Count;  // unsigned
typedef size_t          Seed;
typedef Count           Seq;
typedef QWORD           IdNo;

typedef QList<Index>    IndexList;
typedef QList<INT>      IntList;
typedef QList<UINT>     UIntList;
typedef QList<QWORD>    QWordList;
typedef QList<FLOAT>    FloatList;

#define countof(array) (sizeof(array) / sizeof(array[0]))


