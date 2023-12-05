#ifndef NODEINPUTSLOT_H
#define NODEINPUTSLOT_H

#include <QWidget>

class CircuitNode;
class NodeOutputSlot;

class NodeInputSlot : public QWidget
{
public:
    NodeInputSlot(int *currentNodeSize, QWidget *parent = nullptr);
    ~NodeInputSlot();

    CircuitNode *node;

    int size = 20;
    int *currentNodeSize;

    NodeOutputSlot *connection = nullptr;
    QPoint position;

    void disconnect();
    void redrawSlot(float multiplier);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // NODEINPUTSLOT_H
