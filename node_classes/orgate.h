#ifndef ORGATE_H
#define ORGATE_H

#include <QLabel>
#include "circuitnode.h"

class OrGate : public CircuitNode
{
public:
    OrGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // ORGATE_H
