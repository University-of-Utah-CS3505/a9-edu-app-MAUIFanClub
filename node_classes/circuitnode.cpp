#include "circuitnode.h"
#include "nodeinputslot.h"
#include "nodeoutputslot.h"
CircuitNode::CircuitNode(int inputCount, bool hasOutput, QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("circuitNode");
    this->setAccessibleName("circuitNode");
    drawNode(1, QPoint(0,0));
//    this->setGeometry(QRect(0, 0, nodeSize, nodeSize));
//    this->setStyleSheet(".circuitNode {background-color: lightblue; border: 3px solid "
//                        "#a4a4a4; border-radius: 5px;} "
//                        ".circuitNode:hover{border: 3px solid #000000;}");
    this->setProperty("class", "circuitNode");

    // Create n input nodes from InputCount | Y Displacement temp for right now.
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
void CircuitNode::drawNode(float sizeMultiplier, QPoint pos)
{
    int offSetSize = currentSize - (nodeSize*sizeMultiplier);
    this->setGeometry(QRect((pos.x() + offSetSize/2) , pos.y() + offSetSize/2, nodeSize*sizeMultiplier, nodeSize*sizeMultiplier));
    //this->setFixedSize(this->currentSize * sizeMultiplier, this->currentSize * sizeMultiplier);
    currentSize = nodeSize * sizeMultiplier;
    this->setStyleSheet(".circuitNode {background-color: lightblue; border: 3px solid "
                        "#a4a4a4; border-radius: 5px;} "
                        ".circuitNode:hover{border: 3px solid #000000;}");
    for(NodeInputSlot* x : inputs)
    {
        x->redrawSlot(sizeMultiplier);
    }
    if(output)
    output->redrawSlot(sizeMultiplier);
}
bool CircuitNode::run()
{
    qDebug() << " Base CircuitNode RUN() ";
    return true;
}

void CircuitNode::moveWidget()
{
    DragableWidget::moveWidget();

    // Update inputs line
    for (unsigned long i = 0; i < inputs.size(); i++) {
        if (inputs[i]->connection == nullptr) {
            continue;
        }

        QPoint inputPos = this->pos() + inputs[i]->pos() + QPoint(2, inputs[i]->size / 2);

        QPoint outputPos = inputs[i]->connection->node->pos() + inputs[i]->connection->pos()
                           + QPoint(inputs[i]->connection->size - 2,
                                    inputs[i]->connection->size / 2);

        inputs[i]->connection->updateLinePos(inputPos, outputPos);
    }

    if (output == nullptr) {
        return;
    }

    if (output->connection == nullptr) {
        return;
    }

    // Update output line
    QPoint outputPos = this->pos() + output->pos() + QPoint(output->size - 2, output->size / 2);

    QPoint inputPos = output->connection->node->pos() + output->connection->pos()
                      + QPoint(2, output->connection->size / 2);

    output->updateLinePos(outputPos, inputPos);
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
