#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQPDF_LIBRARY)
#define IRQPDF_EXPORT Q_DECL_EXPORT
#else
#define IRQPDF_EXPORT Q_DECL_IMPORT
#endif
