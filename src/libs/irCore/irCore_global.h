#pragma once

#include <QtCore/qglobal.h>

#if defined(IRCORE_LIBRARY)
#define IRCORE_EXPORT Q_DECL_EXPORT
#else
#define IRCORE_EXPORT Q_DECL_IMPORT
#endif
