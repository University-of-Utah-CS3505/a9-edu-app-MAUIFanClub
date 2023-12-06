#include "nodeoutputslot.h"
#include "node_classes/circuitnode.h"

NodeOutputSlot::NodeOutputSlot(QWidget *mainWindow, QWidget *parent)
{
    // this->lineManager = new NodeLineConnectionManager(mainWindow);

    this->setParent(parent);
    this->setObjectName("Output Node");
    this->setStyleSheet("* {background-color:red;}");
    this->setGeometry(QRect(180, 90, size, size));

    this->setProperty("class", "circuitNode");
    this->node = static_cast<CircuitNode *>(parent);
}

NodeOutputSlot::~NodeOutputSlot() {}

void NodeOutputSlot::mousePressEvent(QMouseEvent *event)
{
    clicked = true;

    if (connection != nullptr) {
        connection->disconnect();
    }
    disconnect();
}

void NodeOutputSlot::mouseMoveEvent(QMouseEvent *event)
{
    if (!clicked) {
        return;
    }

    QPoint slotScenePos = this->parentWidget()->pos() + this->pos() + QPoint(size - 2, size / 2);
    emit node->circuitSignalHandler->nodeSlotDrag(slotScenePos, event->scenePosition().toPoint());
}

void NodeOutputSlot::mouseReleaseEvent(QMouseEvent *event)
{
    clicked = false;

    QPoint pos = event->globalPosition().toPoint();

    // Converts object mouse was over to inputSlot. If it is not an input slot it return null;
    NodeInputSlot *inputSlot = dynamic_cast<NodeInputSlot *>(QApplication::widgetAt(pos));

    // Check if mouse was over input slot
    if (inputSlot == NULL) {
        emit node->circuitSignalHandler->updateLines();
        return;
    }

    // Checks to make sure input slot is not on same node
    for (int i = 0; i < node->inputs.size(); i++) {
        if (node->inputs[i] == inputSlot) {
            return;
        }
    }

    // Disconnects the input slots previous connection
    if (inputSlot->connection != nullptr) {
        inputSlot->connection->disconnect();
    }

    connection = inputSlot;
    inputSlot->connection = this;

    emit node->circuitSignalHandler->updateLines();
}

void NodeOutputSlot::disconnect()
{
    connection = nullptr;
    emit node->circuitSignalHandler->updateLines();
}
