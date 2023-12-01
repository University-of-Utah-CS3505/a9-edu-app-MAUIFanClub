#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include <QLabel>
#include "circuitnode.h"

class OutputNode : public CircuitNode
{
public:
    OutputNode();
    ~OutputNode();

    QLabel *outputLabel;

    virtual bool run();
};

#endif // OUTPUTNODE_H
