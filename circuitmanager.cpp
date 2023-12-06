#include "circuitmanager.h"

CircuitManager::CircuitManager(QWidget *levelWidget)
{
    this->levelWidget = levelWidget;
    lineManager = new NodeLineConnectionManager(&nodes, levelWidget);
}

void CircuitManager::run()
{
    if (nodes.size() == 0) {
        QMessageBox::information(levelWidget, tr("Error"), tr("THERE ARE NO NODES!"));
        return;
    }

    if (isGraphCompleted()) {
        runEachOutput();
    } else {
        QMessageBox::information(levelWidget,
                                 tr("Error"),
                                 tr("GRAPH IS NOT COMPLETED! \n\n - Right Click To Delete Nodes"));
    }
}

void CircuitManager::runEachOutput()
{
    for (unsigned long i = 0; i < outputNodes.size(); i++) {
        outputNodes[i]->run();
    }
}

// Checks to see if the graph is fully filled out. Each slot has a connection of some sort.
bool CircuitManager::isGraphCompleted()
{
    // Loops over each node
    for (unsigned long i = 0; i < nodes.size(); i++) {
        // Loops over nodes input slots
        for (unsigned long inputIndex = 0; inputIndex < nodes[i]->inputs.size(); inputIndex++) {
            if (nodes[i]->inputs[inputIndex]->connection == nullptr) {
                return false;
            }
        }

        // Checks output slot (if instantiated)
        if (nodes[i]->output != nullptr && nodes[i]->output->connection == nullptr) {
            return false;
        }
    }

    return true;
}

void CircuitManager::deleteNode(CircuitNode *nodeToDelete)
{
    nodes.erase(std::remove(nodes.begin(), nodes.end(), nodeToDelete), nodes.end());

    if (nodeToDelete->objectName() == "outputNode") {
        outputNodes.erase(std::remove(outputNodes.begin(), outputNodes.end(), nodeToDelete),
                          outputNodes.end());
    }
}

/*    ----    NODE CREATION METHODS   ----    */

void CircuitManager::handleNewNode(CircuitNode *node)
{
    levelWidget->layout()->addWidget(node);
    lineManager->createCanvas(node);

    QPoint nodePos(10, 30);

    // Finds open position for node.
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->pos() == nodePos) {
            nodePos = QPoint(nodePos.x() + 10, nodePos.y() + 10);
        }
    }

    node->move(nodePos);
    nodes.push_back(node);

    // Node Deleted Connection
    connect(node->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        deleteNode(node);
        lineManager->nodeDeleted(node);
    });

    // Update Lines Connection
    connect(node->circuitSignalHandler, &CircuitSignalHandler::updateLines, this, [=]() {
        lineManager->updateCanvas(node);
    });

    // Slot Drag Connection
    connect(node->circuitSignalHandler,
            &CircuitSignalHandler::nodeSlotDrag,
            this,
            [=](QPoint slotPos, QPoint mousePos) {
                lineManager->drawSlotDrag(node, slotPos, mousePos);
            });

    // Node Drag Connection
    connect(node->circuitSignalHandler, &CircuitSignalHandler::nodeMoved, this, [=]() {
        lineManager->nodeMoved(node);
    });
}

/*  ZOOM FUNCTIONS  */

float clamp(float d, float min, float max)
{
    const float t = d < min ? min : d;
    return t > max ? max : t;
}

void CircuitManager::zoomIn()
{ // Mouse wheel moved up
    for (CircuitNode *x : nodes) {
        currentZoom = clamp(currentZoom + 0.1, 0.4, 1);
        x->drawNode(currentZoom, x->pos());
    }
}

void CircuitManager::zoomOut()
{
    for (CircuitNode *x : nodes) {
        currentZoom = clamp(currentZoom - 0.1, 0.4, 1);
        x->drawNode(currentZoom, x->pos());
    }
}

/*  NODE CREATION FUNCTIONS  */

void CircuitManager::createAndGate()
{
    handleNewNode(new AndGate(levelWidget));
}

void CircuitManager::createNAndGate()
{
    handleNewNode(new nAndGate(levelWidget));
}

void CircuitManager::createOrGate()
{
    handleNewNode(new OrGate(levelWidget));
}

void CircuitManager::createNOrGate()
{
    handleNewNode(new nOrGate(levelWidget));
}

void CircuitManager::createInputNode()
{
    handleNewNode(new InputNode(levelWidget));
}

void CircuitManager::createOutputNode()
{
    OutputNode *outputNode = new OutputNode(levelWidget);
    outputNodes.push_back(outputNode);
    handleNewNode(outputNode);
}
