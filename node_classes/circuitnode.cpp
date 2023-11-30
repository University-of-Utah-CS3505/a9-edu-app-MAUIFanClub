#include "circuitnode.h"

CircuitNode::CircuitNode(int inputCount)
{
    this->setGeometry(QRect(0, 0, nodeSize, nodeSize));
    this->setStyleSheet(
        "* {background-color: lightblue; border: 3px solid #a4a4a4; border-radius: 5px;} "
        "*:hover{border: 3px solid #000000;}");
    this->setObjectName("Main Node Widget");

    // Create n input nodes from InputCount | Y Displacement temp for right now.
    for (int i = 0; i < inputCount; i++) {
        InputNode *inputNode = new InputNode(this);
        inputs.push_back(inputNode);

        inputs[i]->move(inputNode->x(), inputNode->y() + inputNodeOffset);
        inputNodeOffset += 30;
    }

    OutputNode outNode = new OutputNode(this);
}

CircuitNode::~CircuitNode() {}

void CircuitNode::Run() {}
