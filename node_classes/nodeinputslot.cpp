#include "nodeinputslot.h"
#include "node_classes/circuitnode.h"

NodeInputSlot::NodeInputSlot(QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("Input Node");
    this->setStyleSheet("* {background-color:green;}");
    this->setGeometry(QRect(0, 90, size, size));

    this->setProperty("class", "circuitNode");
    this->node = static_cast<CircuitNode *>(parent);
}

NodeInputSlot::~NodeInputSlot() {}

void NodeInputSlot::mousePressEvent(QMouseEvent *event) {}

void NodeInputSlot::mouseReleaseEvent(QMouseEvent *event) {}
