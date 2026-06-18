#pragma once

#include <opencv2/core/types.hpp>

#include <QPoint>

class qcvPoint : public cv::Point
{
public: // ctors
    qcvPoint();
    qcvPoint(const QPoint pt);
    qcvPoint(const int x0, const int y0);

public: // const
    int xpt() const;
    int ypt() const;

public: // non-const
    void set(const int x0, const int y0);
    void xpt(const int x0);
    void ypt(const int y0);

};

inline int qcvPoint::xpt() const { return x; }
inline int qcvPoint::ypt() const { return y; }
inline void qcvPoint::set(const int x0, const int y0) { xpt(x0), ypt(y0); }
inline void qcvPoint::xpt(const int x0) { x = x0; }
inline void qcvPoint::ypt(const int y0) { y = y0; }
