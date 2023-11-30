#ifndef NODEINPUTSLOT_H
#define NODEINPUTSLOT_H

#include <QWidget>

class NodeInputSlot : public QWidget
{
public:
    NodeInputSlot(QWidget *parent = nullptr);
    ~NodeInputSlot();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int size = 20;
};

#endif // NODEINPUTSLOT_H
