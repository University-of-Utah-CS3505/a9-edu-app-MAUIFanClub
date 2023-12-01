#ifndef ANDGATE_H
#define ANDGATE_H

#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include "circuitnode.h"

class AndGate : public CircuitNode
{
public:
    AndGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // ANDGATE_H
