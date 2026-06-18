#ifndef QTCVUTILS_GLOBAL_H
#define QTCVUTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTCVUTILS_LIBRARY)
#define QTCVUTILS_EXPORT Q_DECL_EXPORT
#else
#define QTCVUTILS_EXPORT Q_DECL_IMPORT
#endif

#endif // QTCVUTILS_GLOBAL_H
