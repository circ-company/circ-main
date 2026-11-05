#pragma once

#include <QWidget>

class QGridLayout;

#include <ColorWheel.h>
#include <Label.h>
#include <Size.h>

class ryFaceGrid : public QWidget
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

public: // const
    const Size gridElements() const;

public: // non-const

public: // static
    Label *dummy(const QColor aBaseColor);

public: // pointers
    QGridLayout * layout();

private:
    const Size cmGridElements=Size(10, 6);
    QGridLayout * mpLayout=nullptr;
};

inline const Size ryFaceGrid::gridElements() const { return cmGridElements; }
inline QGridLayout *ryFaceGrid::layout() { Q_CHECK_PTR(mpLayout); return mpLayout; }
