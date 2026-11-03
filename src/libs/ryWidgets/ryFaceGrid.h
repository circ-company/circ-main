#pragma once

#include <QGridLayout>

#include <ColorWheel.h>

class ryFaceGrid : public QGridLayout
{
public:
    ryFaceGrid(QWidget *parent = nullptr);

public slots: // non-const
    void run();
    void initialize();
    void setup();
    void ready();

signals:
    void running();
    void initialized();
    void setuped();
    void readied();

private:
    ColorWheel mBaseColorWheel;
};
