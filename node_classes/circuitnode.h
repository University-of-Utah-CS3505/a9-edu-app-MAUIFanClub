#ifndef CIRCUITNODE_H
#define CIRCUITNODE_H

#include <QDebug>
#include "dragablewidget.h"
#include "inputnode.h"
#include "outputnode.h"
#include <vector>

using std::vector;

class CircuitNode : public DragableWidget
{
public:
    CircuitNode(int inputCount);
    ~CircuitNode();

    vector<InputNode *> inputs;
    OutputNode *output;

    virtual void Run();

protected:
    int inputNodeOffset = 0;

    int nodeSize = 200;
};

#endif // CIRCUITNODE_H
