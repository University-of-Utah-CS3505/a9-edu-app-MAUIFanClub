#ifndef NODEOUTPUTSLOT_H
#define NODEOUTPUTSLOT_H

#include <QApplication>
#include <QMouseEvent>
#include <QWidget>
#include "nodeinputslot.h"

class CircuitNode;

class NodeOutputSlot : public QWidget
{
public:
    NodeOutputSlot(QWidget *mainWindow, int *currentNodeSize, QWidget *parent = nullptr);
    ~NodeOutputSlot();

    NodeInputSlot *connection = nullptr;

    bool clicked = false;
    CircuitNode *node;
    void redrawSlot(float multiplier);
    int size = 20;

    void disconnect();

    int currentSize;
    int currentLocation;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int *currentNodeSize;
};

#endif // NODEOUTPUTSLOT_H
