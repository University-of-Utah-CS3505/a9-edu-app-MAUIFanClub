#ifndef NODEOUTPUTSLOT_H
#define NODEOUTPUTSLOT_H

#include <QApplication>
#include <QMouseEvent>
#include <QWidget>
#include "nodeinputslot.h"
#include "nodelineconnectionmanager.h"

class CircuitNode;

class NodeOutputSlot : public QWidget
{
public:
    NodeOutputSlot(QWidget *mainWindow, int *currentNodeSize, QWidget *parent = nullptr);
    ~NodeOutputSlot();

    NodeInputSlot *connection = nullptr;
    NodeLineConnectionManager *lineManager;

    CircuitNode *node;
    void redrawSlot(float multiplier);
    int size = 20;

    void disconnect();
    void updateLinePos(QPoint p1, QPoint p2);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int *currentNodeSize;
};

#endif // NODEOUTPUTSLOT_H
