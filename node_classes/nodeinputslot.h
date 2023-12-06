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

    NodeOutputSlot *connection = nullptr;

    bool clicked = false;
    CircuitNode *node;

    int size = 20;
    int *currentNodeSize;

    QPoint position;

    void disconnect();
    void redrawSlot(float multiplier);

    int currentSize;
    int currentLocation;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // NODEINPUTSLOT_H
