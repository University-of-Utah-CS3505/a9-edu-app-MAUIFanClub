#include "nodeoutputslot.h".h "

NodeOutputSlot::NodeOutputSlot(QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("Output Node");
    this->setStyleSheet("* {background-color:red;}");
    this->setGeometry(QRect(180, 90, size, size));

    this->setProperty("class", "circuitNode");
}

NodeOutputSlot::~NodeOutputSlot() {}

void NodeOutputSlot::mousePressEvent(QMouseEvent *event) {}

void NodeOutputSlot::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->globalPosition().toPoint();
    NodeInputSlot *inputSlot = dynamic_cast<NodeInputSlot *>(QApplication::widgetAt(pos));

    if (inputSlot == NULL) {
        qDebug() << "NO INPUT SLOT FOUND";
        return;
    }

    qDebug() << "INPUT NODE FOUND: " << inputSlot->objectName() << " AT: " << pos;
}
