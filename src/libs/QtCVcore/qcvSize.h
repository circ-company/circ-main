#pragma once

#include <opencv2/core/types.hpp>

#include <QSize>


class qcvSize : public cv::Size
{
public: // ctors
    qcvSize();
    qcvSize(const QSize sz);
    qcvSize(const int w, const int h);

public: // const
    int w() const;
    int h() const;

public: // non-const
    void w(const int wd);
    void h(const int ht);

};

inline int qcvSize::w() const { return width; }
inline int qcvSize::h() const { return height; }
inline void qcvSize::w(const int wd) { width = wd; }
inline void qcvSize::h(const int ht) { height = ht; }
