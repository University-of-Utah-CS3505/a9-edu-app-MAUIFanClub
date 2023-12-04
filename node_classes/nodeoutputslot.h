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
    NodeOutputSlot(QWidget *mainWindow, QWidget *parent = nullptr);
    ~NodeOutputSlot();

    NodeInputSlot *connection = nullptr;

    bool clicked = false;
    CircuitNode *node;

    int size = 20;

    void disconnect();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // NODEOUTPUTSLOT_H
