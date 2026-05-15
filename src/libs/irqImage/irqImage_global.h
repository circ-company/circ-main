#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQIMAGE_LIBRARY)
#define IRQIMAGE_EXPORT Q_DECL_EXPORT
#else
#define IRQIMAGE_EXPORT Q_DECL_IMPORT
#endif
