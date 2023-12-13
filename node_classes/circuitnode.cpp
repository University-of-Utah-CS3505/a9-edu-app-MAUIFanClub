#include "circuitnode.h"
#include "nodeinputslot.h"
#include "nodeoutputslot.h"
CircuitNode::CircuitNode(int inputCount, bool hasOutput, QWidget *parent)
{
    this->setParent(parent);
    this->setObjectName("circuitNode");
    this->setAccessibleName("circuitNode");
    this->setProperty("class", "circuitNode");

    drawNode(1, QPoint(0, 0));

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
    float offSetSize = (float)currentSize - (nodeSize * sizeMultiplier);

    currentSize = nodeSize * sizeMultiplier;
    this->setGeometry(
        QRect((pos.x() + offSetSize / 2), pos.y() + offSetSize / 2, currentSize, currentSize));

    // Scales Children
    if (this->children().size() != 0) {
        // Node Image Scale
        if (imagePath != "") {
            QLabel *imageLabel = static_cast<QLabel *>(this->children()[0]);
            imageLabel->setGeometry(QRect(0, 0, currentSize, currentSize));
            imageLabel->setPixmap(QPixmap(imagePath).scaled(QSize(currentSize, currentSize),
                                                            Qt::KeepAspectRatio,
                                                            Qt::SmoothTransformation));
        }
        // Input Node Button Scale
        else if (this->objectName() == "inputNode") {
            QPushButton *inputBtn = static_cast<QPushButton *>(this->children()[1]);
            inputBtn->setGeometry(QRect(25 * sizeMultiplier,
                                        25 * sizeMultiplier,
                                        150 * sizeMultiplier,
                                        150 * sizeMultiplier));
        }
        // Output Node Text Label Scale
        else {
            QLabel *outputLabel = static_cast<QLabel *>(this->children()[1]);
            outputLabel->setGeometry(QRect(25 * sizeMultiplier,
                                           25 * sizeMultiplier,
                                           150 * sizeMultiplier,
                                           150 * sizeMultiplier));
        }
    }

    this->setStyleSheet(".circuitNode {background-color: white; border: 3px solid "
                        "#a4a4a4; border-radius: 5px;} "
                        ".circuitNode:hover{border: 3px solid #000000;}");

    for (NodeInputSlot *x : inputs) {
        x->redrawSlot(sizeMultiplier);
    }

    if (output) {
        output->redrawSlot(sizeMultiplier);
    }
}

bool CircuitNode::run()
{
    qDebug() << " Base CircuitNode RUN() :|: How Did You Get Here? >:)";
    return true;
}

void CircuitNode::moveWidget()
{
    DragableWidget::moveWidget();

    emit circuitSignalHandler->nodeMoved();
}

void CircuitNode::mousePressEvent(QMouseEvent *event)
{
    dragableWidgetSize = currentSize;

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
