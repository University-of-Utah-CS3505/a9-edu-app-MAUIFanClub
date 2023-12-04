#include "circuitnode.h"

CircuitNode::CircuitNode(int inputCount, bool hasOutput, QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("circuitNode");
    this->setAccessibleName("circuitNode");

    this->setGeometry(QRect(0, 0, nodeSize, nodeSize));
    this->setStyleSheet(".circuitNode {background-color: lightblue; border: 3px solid "
                        "#a4a4a4; border-radius: 5px;} "
                        ".circuitNode:hover{border: 3px solid #000000;}");
    this->setProperty("class", "circuitNode");

    // Create n input nodes from InputCount
    for (int i = 0; i < inputCount; i++) {
        NodeInputSlot *inputSlot = new NodeInputSlot(this);
        inputs.push_back(inputSlot);
    }

    if (hasOutput) {
        output = new NodeOutputSlot(parent, this);
    }

    circuitSignalHandler = new CircuitSignalHandler();
}

CircuitNode::~CircuitNode() {}

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

    emit circuitSignalHandler->updateLines();
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

        inputs[i]->connection->disconnect();
        inputs[i]->disconnect();
    }

    if (output != nullptr && output->connection != nullptr) {
        output->connection->disconnect();
        output->disconnect();
    }

    emit circuitSignalHandler->nodeDeleted();
    delete this;
}
