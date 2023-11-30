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
    AndGate();

    void Run();
};

#endif // ANDGATE_H
