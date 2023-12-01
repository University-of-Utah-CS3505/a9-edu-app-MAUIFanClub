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
    NodeOutputSlot(QWidget *parent = nullptr);
    ~NodeOutputSlot();

    NodeInputSlot *connection = nullptr;

    void disconnect();
    CircuitNode *node;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // NODEOUTPUTSLOT_H
