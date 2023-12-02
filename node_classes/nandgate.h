#ifndef NANDGATE_H
#define NANDGATE_H

#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include "circuitnode.h"

class nAndGate : public CircuitNode
{
public:
    nAndGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // ANDGATE_H
