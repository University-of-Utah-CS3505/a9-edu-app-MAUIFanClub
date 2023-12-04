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
float clampTemp(float d, float min, float max) {
    const float t = d < min ? min : d;
    return t > max ? max : t;
}
NodeInputSlot::~NodeInputSlot() {}
void NodeInputSlot::redrawSlot(float multiplier)
{
    float localMultiplier = clampTemp(multiplier, 0.6, 1);
    this->setGeometry(QRect(0, 90*(multiplier - 0.05), size*localMultiplier, size*localMultiplier));
}
void NodeInputSlot::mousePressEvent(QMouseEvent *event) {}

void NodeInputSlot::mouseReleaseEvent(QMouseEvent *event) {}

void NodeInputSlot::disconnect()
{
    connection = nullptr;
}
