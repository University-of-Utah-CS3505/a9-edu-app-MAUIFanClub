#include "nodeoutputslot.h"
#include "node_classes/circuitnode.h"

NodeOutputSlot::NodeOutputSlot(QWidget *mainWindow, QWidget *parent)
{
    this->lineManager = new NodeLineConnectionManager(mainWindow);

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
    QPoint slotScenePos = this->parentWidget()->pos() + this->pos() + QPoint(size - 2, size / 2);

    if (connection != nullptr) {
        connection->disconnect();
    }
    disconnect();

    lineManager->startLineDraw(slotScenePos);
}

void NodeOutputSlot::mouseMoveEvent(QMouseEvent *event)
{
    lineManager->updateLineDraw(event->scenePosition().toPoint());
}

void NodeOutputSlot::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint pos = event->globalPosition().toPoint();
    NodeInputSlot *inputSlot = dynamic_cast<NodeInputSlot *>(QApplication::widgetAt(pos));

    if (inputSlot == NULL) {
        lineManager->clearCanvas();
        return;
    }

    if (inputSlot->connection != nullptr) {
        inputSlot->connection->disconnect();
    }

    connection = inputSlot;
    inputSlot->connection = this;

    QPoint slotScenePos = this->parentWidget()->pos() + this->pos() + QPoint(size - 2, size / 2);
    QPoint inputSlotPos = inputSlot->node->pos() + inputSlot->pos()
                          + QPoint(2, inputSlot->size / 2);

    lineManager->drawLine(slotScenePos, inputSlotPos);
    lineManager->endLineDraw();
}

void NodeOutputSlot::disconnect()
{
    connection = nullptr;
    lineManager->clearCanvas();
}

void NodeOutputSlot::updateLinePos(QPoint p1, QPoint p2)
{
    lineManager->drawLine(p1, p2);
}
