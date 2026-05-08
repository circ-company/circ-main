#pragma once

#include <QtCore/qglobal.h>

#if defined(IRTYPES_LIBRARY)
#define IRTYPES_EXPORT Q_DECL_EXPORT
#else
#define IRTYPES_EXPORT Q_DECL_IMPORT
#endif
