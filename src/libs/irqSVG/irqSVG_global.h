#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQSVG_LIBRARY)
#define IRQSVG_EXPORT Q_DECL_EXPORT
#else
#define IRQSVG_EXPORT Q_DECL_IMPORT
#endif
