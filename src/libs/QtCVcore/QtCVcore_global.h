#ifndef QTCVCORE_GLOBAL_H
#define QTCVCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTCVCORE_LIBRARY)
#define QTCVCORE_EXPORT Q_DECL_EXPORT
#else
#define QTCVCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // QTCVCORE_GLOBAL_H
