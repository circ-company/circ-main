#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQCORE_LIBRARY)
#define IRQCORE_EXPORT Q_DECL_EXPORT
#else
#define IRQCORE_EXPORT Q_DECL_IMPORT
#endif
