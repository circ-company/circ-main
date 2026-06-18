/*! \file cvqPoint.h cv::Point from QPoint
 */

#include "cvqPoint.h"


/*! \class cvqPoint
 *  \brief  cv::Point from QPoint
 */

/*! \fn
 *  Constructs a null cv::Point
 */
cvqPoint::cvqPoint() {;}

/*! \fn
 *  Constructs a cv::Point from QPoint
 */
cvqPoint::cvqPoint(const cv::Point cvpt) : QPoint(cvpt.x, cvpt.y) {;}

/*! \fn
 *  Constructs a cv::Point from int x and y
 */
cvqPoint::cvqPoint(const int x0, const int y0) : QPoint(x0, y0) {;}
