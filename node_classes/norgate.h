#ifndef NORGATE_H
#define NORGATE_H

#include <QLabel>
#include "circuitnode.h"

class nOrGate : public CircuitNode
{
public:
    nOrGate(QWidget *parent = nullptr);

    virtual bool run();
};

#endif // ORGATE_H
