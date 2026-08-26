#pragma once

#include <QtCore/qglobal.h>

#if defined(QTCVFACEREC_LIBRARY)
#define QTCVFACEREC_EXPORT Q_DECL_EXPORT
#else
#define QTCVFACEREC_EXPORT Q_DECL_IMPORT
#endif
