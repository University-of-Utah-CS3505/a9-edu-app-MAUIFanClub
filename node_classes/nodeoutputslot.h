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
    NodeOutputSlot(QWidget *mainWindow, QWidget *parent = nullptr);
    ~NodeOutputSlot();

    NodeInputSlot *connection = nullptr;
    NodeLineConnectionManager *lineManager;

    void disconnect();
    CircuitNode *node;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // NODEOUTPUTSLOT_H
