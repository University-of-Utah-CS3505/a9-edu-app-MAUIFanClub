#ifndef XORGATE_H
#define XORGATE_H

#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include "circuitnode.h"

class xOrGate : public CircuitNode
{
public:
    xOrGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // XORGATE_H
