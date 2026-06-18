#pragma once

#include <QPoint>

#include <opencv2/core/types.hpp>

class cvqPoint : public QPoint
{
public: // ctors
    cvqPoint();
    cvqPoint(const cv::Point cvpt);
    cvqPoint(const int x0, const int y0);

public: // const

public: // non-const
    void set(const int x0, const int y0);
    void x(const int x0);
    void y(const int y0);

};

inline void cvqPoint::set(const int x0, const int y0) { x(x0), y(y0); }
inline void cvqPoint::x(const int x0) { setX(x0); }
inline void cvqPoint::y(const int y0) { setY(y0); }
