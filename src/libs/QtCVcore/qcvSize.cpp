/*! \file cvqSize.h cv::Size from QSize
 */

#include "qcvSize.h"

/*! \class cvqSize
 *  \brief  cv::Size from QSize
 */

/*! \fn
 *  Constructs a null cv::Size
 */
qcvSize::qcvSize() {;}

/*! \fn
 *  Constructs a cv::Size from QSize
 */
qcvSize::qcvSize(const QSize sz) : cv::Size(sz.width(), sz.height()) {;}

/*! \fn
 *  Constructs a cv::Size from int width and height
 */
qcvSize::qcvSize(const int w, const int h) : cv::Size(w, h) {;}


