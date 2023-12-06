#include "circuitnode.h"
#include "nodeinputslot.h"
#include "nodeoutputslot.h"
CircuitNode::CircuitNode(int inputCount, bool hasOutput, QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("circuitNode");
    this->setAccessibleName("circuitNode");
    drawNode(1, QPoint(0, 0));
    this->setProperty("class", "circuitNode");

    // Create n input nodes from InputCount
    for (int i = 0; i < inputCount; i++) {
        NodeInputSlot *inputSlot = new NodeInputSlot(&currentSize, this);
        inputs.push_back(inputSlot);
    }

    if (hasOutput) {
        output = new NodeOutputSlot(parent, &currentSize, this);
    }

    circuitSignalHandler = new CircuitSignalHandler();
}

CircuitNode::~CircuitNode() {}

void CircuitNode::drawNode(float sizeMultiplier, QPoint pos)
{
    // Offset size ends up being -20, 0, 20. However there is a small deviation by one. So the number gets hard set below.
    float offSetSize = currentSize - (nodeSize * sizeMultiplier);
    if (offSetSize != 0) {
        offSetSize = (offSetSize < 0) ? -20 : 20;
    }

    currentSize = nodeSize * sizeMultiplier;
    this->setGeometry(
        QRect((pos.x() + offSetSize / 2), pos.y() + offSetSize / 2, currentSize, currentSize));

    this->setStyleSheet(".circuitNode {background-color: white; border: 3px solid "
                        "#a4a4a4; border-radius: 5px;} "
                        ".circuitNode:hover{border: 3px solid #000000;}");

    for (NodeInputSlot *x : inputs) {
        x->redrawSlot(sizeMultiplier);
    }

    if (output)
        output->redrawSlot(sizeMultiplier);
}
bool CircuitNode::run()
{
    qDebug() << " Base CircuitNode RUN() :|: How Did You Get Here? >:)";
    return true;
}

void CircuitNode::moveWidget()
{
    DragableWidget::moveWidget();

    bool inputsHaveConnection = false;

    // Checks used to see if the rest of the canvas needs to be updated. //

    // Checks if input connections have a connection.
    for (unsigned long i = 0; i < inputs.size(); i++) {
        if (inputs[i]->connection == nullptr) {
            continue;
        }
        inputsHaveConnection = true;
        break;
    }

    // Checks if output exists / has connection & if inputs have a connection. Returns if both are false.
    if ((output == nullptr || output->connection == nullptr) && !inputsHaveConnection) {
        return;
    }

    emit circuitSignalHandler->nodeMoved();
}

void CircuitNode::mousePressEvent(QMouseEvent *event)
{
    DragableWidget::mousePressEvent(event);

    if (event->button() == Qt::RightButton) {
        deleteNode();
    }
}

void CircuitNode::deleteNode()
{
    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i]->connection == nullptr) {
            continue;
        }

        CircuitNode *connectedNode = inputs[i]->connection->node;

        inputs[i]->connection->disconnect();
        inputs[i]->disconnect();

        emit connectedNode->circuitSignalHandler->updateLines();
    }

    if (output != nullptr && output->connection != nullptr) {
        CircuitNode *connectedNode = output->connection->node;

        output->connection->disconnect();
        output->disconnect();

        emit connectedNode->circuitSignalHandler->updateLines();
    }

    emit circuitSignalHandler->nodeDeleted();
    delete this;
}
