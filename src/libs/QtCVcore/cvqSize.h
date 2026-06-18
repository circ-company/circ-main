#pragma once

#include <QSize>

#include <opencv2/core/types.hpp>

class cvqSize : public QSize
{
public: // ctors
    cvqSize();
    cvqSize(const cv::Size cvsz);
    cvqSize(const int wd, const int ht);

public: // const
    int w() const;
    int h() const;

public: // non-const
    void set(const int wd, const int ht);
    void w(const int wd);
    void h(const int ht);

};

inline int cvqSize::w() const { return width(); }
inline int cvqSize::h() const { return height(); }
inline void cvqSize::set(const int wd, const int ht) { setWidth(wd), setHeight(ht); }
inline void cvqSize::w(const int wd) { setWidth(wd); }
inline void cvqSize::h(const int ht) { setHeight(ht); }
