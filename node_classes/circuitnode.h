#ifndef CIRCUITNODE_H
#define CIRCUITNODE_H

#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPushButton>
#include "circuitsignalhandler.h"
#include "dragablewidget.h"
#include "nodeinputslot.h"
#include "nodeoutputslot.h"
#include <random>
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

    void drawNode(float sizeMultiplier, QPoint pos);
    void deleteNode();

    virtual bool run();
    virtual void moveWidget();

protected:
    int currentSize = 200;

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CIRCUITNODE_H
