#pragma once

#include <Label.h>

#include <QColor>

#include <Size.h>

class FaceWidget : public Label
{
    Q_OBJECT
public: // ctors
    FaceWidget(QWidget *parent=nullptr);

public slots:

signals:

public: // const
    const Size baseSize() const;
    QColor baseColor() const;


public: // non-const
    void dummy(const Index ix=-1);

private:
    QColor mBaseColor=Qt::blue;
    QList<QColor> mBaseColors;
};

inline const Size FaceWidget::baseSize() const { return Size(128); }
inline QColor FaceWidget::baseColor() const { return mBaseColor; }
