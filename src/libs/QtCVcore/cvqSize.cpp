/*! \file cvqSize.h QSize from cv::Size
 */

#include "cvqSize.h"

/*! \class cvqSize
 *  \brief  QSize from cv::Size
 */

/*! \fn
 *  Constructs a null QSize
 */
cvqSize::cvqSize() {;}

/*! \fn
 *  Constructs a QSize from cv::Size
 */
cvqSize::cvqSize(const cv::Size cvsz) : QSize(cvsz.width, cvsz.height) {;}

/*! \fn
 *  Constructs a QSize from int width and height
 */
cvqSize::cvqSize(const int wd, const int ht) : QSize(wd, ht) {;}

