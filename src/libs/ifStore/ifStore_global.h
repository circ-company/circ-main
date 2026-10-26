#pragma once

#include <QtCore/qglobal.h>

#if defined(IFSTORE_LIBRARY)
#define IFSTORE_EXPORT Q_DECL_EXPORT
#else
#define IFSTORE_EXPORT Q_DECL_IMPORT
#endif
