#ifndef XNORGATE_H
#define XNORGATE_H

#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include "circuitnode.h"

class XnOrGate : public CircuitNode
{
public:
    XnOrGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // XNORGATE_H
