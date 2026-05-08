#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQPRINT_LIBRARY)
#define IRQPRINT_EXPORT Q_DECL_EXPORT
#else
#define IRQPRINT_EXPORT Q_DECL_IMPORT
#endif
