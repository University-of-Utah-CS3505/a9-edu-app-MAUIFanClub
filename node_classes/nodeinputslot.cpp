#include "nodeinputslot.h"
#include "node_classes/circuitnode.h"

NodeInputSlot::NodeInputSlot(int *currentNodeSize, QWidget *parent)
{
    this->currentNodeSize = currentNodeSize;

    this->setParent(parent);
    this->setObjectName("Input Node");
    this->setStyleSheet("* {background-color:green;}");
    this->setGeometry(QRect(0, 90, size, size));

    this->setProperty("class", "circuitNode");
    this->node = static_cast<CircuitNode *>(parent);
}

NodeInputSlot::~NodeInputSlot() {}

float clamp1(float d, float min, float max)
{
    const float t = d < min ? min : d;
    return t > max ? max : t;
}

void NodeInputSlot::redrawSlot(float multiplier)
{
    float localMultiplier = clamp1(multiplier, 0.6, 1);
    int currentSize = size * localMultiplier;
    int currentLocation = position.y() * multiplier;
    this->setGeometry(QRect(0, currentLocation, currentSize, currentSize));
}

void NodeInputSlot::mousePressEvent(QMouseEvent *event) {}

void NodeInputSlot::mouseReleaseEvent(QMouseEvent *event) {}

void NodeInputSlot::disconnect()
{
    connection = nullptr;
}
