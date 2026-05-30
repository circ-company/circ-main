#pragma once

#include <QtCore/qglobal.h>

#if defined(IRSTORE_LIBRARY)
#define IRSTORE_EXPORT Q_DECL_EXPORT
#else
#define IRSTORE_EXPORT Q_DECL_IMPORT
#endif
