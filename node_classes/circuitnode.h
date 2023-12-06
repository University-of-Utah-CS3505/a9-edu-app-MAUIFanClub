#ifndef CIRCUITNODE_H
#define CIRCUITNODE_H

#include <QDebug>
#include <QLabel>
#include <QPushButton>
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

    int nodeSize = 200;
    QString imagePath;

    vector<NodeInputSlot *> inputs;
    NodeOutputSlot *output = nullptr;

    CircuitSignalHandler *circuitSignalHandler;

    virtual bool run();
    virtual void moveWidget();
    void drawNode(float sizeMultiplier, QPoint pos);
    void deleteNode();

protected:
    int currentSize = 200;

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CIRCUITNODE_H
