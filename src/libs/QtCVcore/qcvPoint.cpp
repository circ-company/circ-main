/*! \file qcvPoint.h cv::Point from QPoint
 */

#include "qcvPoint.h"

/*! \class qcvPoint
 *  \brief  cv::Point from QPoint
 */

/*! \fn
 *  Constructs a null cv::Point
 */
qcvPoint::qcvPoint() {;}

/*! \fn
 *  Constructs a cv::Point from QPoint
 */
qcvPoint::qcvPoint(const QPoint pt) : cv::Point(pt.x(), pt.y()) {;}

/*! \fn
 *  Constructs a cv::Point from int x and y
 */
qcvPoint::qcvPoint(const int x0, const int y0) : cv::Point(x0, y0) {;}
