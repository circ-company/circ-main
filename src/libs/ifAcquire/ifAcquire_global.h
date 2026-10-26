#pragma once

#include <QtCore/qglobal.h>

#if defined(IFACQUIRE_LIBRARY)
#define IFACQUIRE_EXPORT Q_DECL_EXPORT
#else
#define IFACQUIRE_EXPORT Q_DECL_IMPORT
#endif
