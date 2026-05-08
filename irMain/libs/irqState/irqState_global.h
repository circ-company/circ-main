#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQSTATE_LIBRARY)
#define IRQSTATE_EXPORT Q_DECL_EXPORT
#else
#define IRQSTATE_EXPORT Q_DECL_IMPORT
#endif
