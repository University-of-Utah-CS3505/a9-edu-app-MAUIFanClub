#ifndef CIRCUITNODE_H
#define CIRCUITNODE_H

#include <QDebug>
#include "nodeinputslot.h"
#include "dragablewidget.h"
#include "nodeoutputslot.h"
#include <vector>

using std::vector;

class CircuitNode : public DragableWidget
{
public:
    CircuitNode(int inputCount, bool hasOutput, QWidget *parent = nullptr);
    ~CircuitNode();

    vector<NodeInputSlot *> inputs;
    NodeOutputSlot *output;

    virtual bool run();

protected:
    int nodeSize = 200;
};

#endif // CIRCUITNODE_H
