#ifndef ORGATE_H
#define ORGATE_H

#include <QLabel>
#include "circuitnode.h"

class OrGate : public CircuitNode
{
public:
    OrGate();

    virtual bool run();
};

#endif // ORGATE_H
