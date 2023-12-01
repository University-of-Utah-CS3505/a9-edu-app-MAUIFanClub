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

    // Create n input nodes from InputCount | Y Displacement temp for right now.
    for (int i = 0; i < inputCount; i++) {
        NodeInputSlot *inputSlot = new NodeInputSlot(this);
        inputs.push_back(inputSlot);
    }

    if (hasOutput) {
        output = new NodeOutputSlot(parent, this);
    }
}

CircuitNode::~CircuitNode() {}

bool CircuitNode::run()
{
    qDebug() << " Base CircuitNode RUN() ";
    return true;
}
