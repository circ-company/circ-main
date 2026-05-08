#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQHELP_LIBRARY)
#define IRQHELP_EXPORT Q_DECL_EXPORT
#else
#define IRQHELP_EXPORT Q_DECL_IMPORT
#endif
