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
    currentSize = size * localMultiplier;
    currentLocation = position.y() * multiplier;

    this->setGeometry(QRect(0, currentLocation, currentSize, currentSize));
}

void NodeInputSlot::mousePressEvent(QMouseEvent *event)
{
    clicked = true;

    if (connection != nullptr) {
        connection->disconnect();
    }
    disconnect();
}

void NodeInputSlot::mouseMoveEvent(QMouseEvent *event)
{
    if (!clicked) {
        return;
    }

    QPoint slotScenePos = this->parentWidget()->pos() + this->pos() + QPoint(2, size / 2);
    emit node->circuitSignalHandler->nodeSlotDrag(slotScenePos, event->scenePosition().toPoint());
}

void NodeInputSlot::mouseReleaseEvent(QMouseEvent *event)
{
    clicked = false;

    QPoint pos = event->globalPosition().toPoint();

    // Converts object mouse was over to inputSlot. If it is not an input slot it return null;
    NodeOutputSlot *outputSlot = dynamic_cast<NodeOutputSlot *>(QApplication::widgetAt(pos));

    // Check if mouse was over input slot
    if (outputSlot == NULL) {
        emit node->circuitSignalHandler->updateLines();
        return;
    }

    // Checks to make sure input slot is not on same node
    if (node->output == outputSlot) {
        return;
    }

    // Disconnects the input slots previous connection
    if (outputSlot->connection != nullptr) {
        outputSlot->connection->disconnect();
    }

    connection = outputSlot;
    outputSlot->connection = this;

    emit node->circuitSignalHandler->updateLines();
    emit connection->node->circuitSignalHandler->updateLines();
}

void NodeInputSlot::disconnect()
{
    connection = nullptr;
    emit node->circuitSignalHandler->updateLines();
}
