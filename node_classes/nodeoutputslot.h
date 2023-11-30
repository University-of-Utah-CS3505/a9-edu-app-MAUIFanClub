#ifndef NODEOUTPUTSLOT_H
#define NODEOUTPUTSLOT_H

#include <QApplication>
#include <QMouseEvent>
#include <QWidget>
#include "nodeinputslot.h"

class NodeOutputSlot : public QWidget
{
public:
    NodeOutputSlot(QWidget *parent = nullptr);
    ~NodeOutputSlot();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // NODEOUTPUTSLOT_H
