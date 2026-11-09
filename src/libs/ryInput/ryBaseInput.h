#pragma once

#include <QObject>

class ryBaseInput : public QObject
{
    Q_OBJECT
public: // types
    enum Scheme
    {
        $null = 0,
        Files,
        Dir,
        HttpCam,
        Tbd,
        $max
    };
    Q_ENUM(Scheme);

public: // ctors
    explicit ryBaseInput(QObject * parent=nullptr);

public slots:

signals:


};
