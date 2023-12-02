#ifndef CIRCUITNODE_H
#define CIRCUITNODE_H

#include <QDebug>
#include "circuitsignalhandler.h"
#include "dragablewidget.h"
#include "nodeinputslot.h"
#include "nodeoutputslot.h"
#include <vector>

using std::vector;

class CircuitNode : public DragableWidget
{
public:
    CircuitNode(int inputCount, bool hasOutput, QWidget *parent = nullptr);
    ~CircuitNode();

    vector<NodeInputSlot *> inputs;
    NodeOutputSlot *output = nullptr;

    CircuitSignalHandler *circuitSignalHandler;

    virtual bool run();
    virtual void moveWidget();

    void deleteNode();

protected:
    int nodeSize = 200;

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CIRCUITNODE_H
