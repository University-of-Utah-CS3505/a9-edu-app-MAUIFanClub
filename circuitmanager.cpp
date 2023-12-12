#include "circuitmanager.h"

CircuitManager::CircuitManager(QWidget *levelWidget)
{
    this->levelWidget = levelWidget;
    lineManager = new NodeLineConnectionManager(&currentZoom, &nodes, levelWidget);

    nodeCount = new int();
    inputCount = new int();
    outputCount = new int();

    box2DManager = new Box2DManager(lineManager);
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

void CircuitManager::loadFile(QString fileName)
{
    QString filepath;

    if (fileName == "") {
        // Opens window to let the user pick a file to load
        filepath = QFileDialog::getOpenFileName(levelWidget,
                                                tr("Open File"),
                                                "C://",
                                                "Circuit Schematic Project (*.csp);;");
    } else {
        filepath = ":saveFiles/CircuitLevels/" + fileName + ".csp";
    }

    QFile loadFile(filepath);

    // Checks if inputted file is correct format
    if (!filepath.contains(".csp")) {
        QMessageBox::information(levelWidget, tr("Error"), tr("Incorrect file format!"));
        return;
    }

    // Checks if file can be opened
    if (!loadFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(levelWidget, tr("Error"), tr("Could not open file :("));
        return;
    }

    // Clears nodes
    if (nodes.size() != 0) {
        clearAllNodes();
    }

    QByteArray loadData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));

    currentZoom = loadDoc["scale"].toDouble();
    *lineManager->currentZoom = currentZoom;

    QJsonArray loadedNodes = loadDoc["nodes"].toArray();

    // Creates Each Node
    for (int i = 0; i < loadedNodes.size(); i++) {
        QString nodeName = loadedNodes[i].toObject()["name"].toString();
        QPoint nodePos = QPoint(loadedNodes[i].toObject()["x"].toInt(),
                                loadedNodes[i].toObject()["y"].toInt());

        if (nodeName.contains("inputNode")) {
            InputNode *inputNode = new InputNode(levelWidget);
            if (loadedNodes[i].toObject()["state"].toInt()) {
                inputNode->toggleState();
            }
            inputNode->setObjectName(nodeName);

            QString outSlot = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            inputNode->output->setObjectName(outSlot);
            handleNewNode(inputNode, nodePos);

        } else if (nodeName.contains("outputNode")) {
            OutputNode *outputNode = new OutputNode(levelWidget);
            outputNode->setObjectName(nodeName);

            QString inSlotName
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();

            outputNode->inputs[0]->setObjectName(inSlotName);
            outputNodes.push_back(outputNode);
            handleNewNode(outputNode, nodePos);

        } else if (nodeName.contains("andGateNode")) {
            AndGate *andGateNode = new AndGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            andGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            andGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            andGateNode->output->setObjectName(outputSlotName);

            andGateNode->setObjectName(nodeName);
            handleNewNode(andGateNode, nodePos);

        } else if (nodeName.contains("nAndGateNode")) {
            nAndGate *nAndGateNode = new nAndGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            nAndGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            nAndGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            nAndGateNode->output->setObjectName(outputSlotName);

            nAndGateNode->setObjectName(nodeName);
            handleNewNode(nAndGateNode, nodePos);

        } else if (nodeName.contains("notGate")) {
            NotGate *notGateNode = new NotGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            notGateNode->inputs[0]->setObjectName(inSlotName1);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            notGateNode->output->setObjectName(outputSlotName);

            notGateNode->setObjectName(nodeName);
            handleNewNode(notGateNode, nodePos);

        } else if (nodeName.contains("xOrGateNode")) {
            xOrGate *xOrGateNode = new xOrGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            xOrGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            xOrGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            xOrGateNode->output->setObjectName(outputSlotName);

            xOrGateNode->setObjectName(nodeName);
            handleNewNode(xOrGateNode, nodePos);

        } else if (nodeName.contains("xnOrGateNode")) {
            XnOrGate *xNOrGateNode = new XnOrGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            xNOrGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            xNOrGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            xNOrGateNode->output->setObjectName(outputSlotName);

            xNOrGateNode->setObjectName(nodeName);
            handleNewNode(xNOrGateNode, nodePos);
        } else if (nodeName.contains("nOrGateNode")) {
            nOrGate *nOrGateNode = new nOrGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            nOrGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            nOrGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            nOrGateNode->output->setObjectName(outputSlotName);

            nOrGateNode->setObjectName(nodeName);
            handleNewNode(nOrGateNode, nodePos);
        } else if (nodeName.contains("orGateNode")) {
            OrGate *orGateNode = new OrGate(levelWidget);

            QString inSlotName1
                = loadedNodes[i].toObject()["inputs"].toArray()[0].toObject()["inputName"].toString();
            orGateNode->inputs[0]->setObjectName(inSlotName1);

            QString inSlotName2
                = loadedNodes[i].toObject()["inputs"].toArray()[1].toObject()["inputName"].toString();
            orGateNode->inputs[1]->setObjectName(inSlotName2);

            QString outputSlotName
                = loadedNodes[i].toObject()["output"].toObject()["outputName"].toString();
            orGateNode->output->setObjectName(outputSlotName);

            orGateNode->setObjectName(nodeName);
            handleNewNode(orGateNode, nodePos);
        }
    }

    // Connects Each Node
    for (int i = 0; i < loadedNodes.size(); i++) {
        QJsonArray inputSlots = loadedNodes[i].toObject()["inputs"].toArray();
        QJsonObject outputSlot = loadedNodes[i].toObject()["output"].toObject();

        for (int inputIndex = 0; inputIndex < inputSlots.size(); inputIndex++) {
            QJsonObject inputSlot = inputSlots[inputIndex].toObject();

            if (inputSlot["connection"] == "") {
                continue;
            }

            CircuitNode *connectedNode = static_cast<CircuitNode *>(
                levelWidget->findChild<QWidget *>(inputSlot["connectionNodeName"].toString()));
            nodes[i]->inputs[inputIndex]->connection = connectedNode->output;
        }

        if (outputSlot["outputName"] == "" || outputSlot["connection"] == "") {
            continue;
        }

        CircuitNode *node = static_cast<CircuitNode *>(
            levelWidget->findChild<QWidget *>(outputSlot["connectionNodeName"].toString()));

        for (int inputIndex = 0; inputIndex < node->inputs.size(); inputIndex++) {
            if (node->inputs[inputIndex]->objectName() == outputSlot["connection"].toString()) {
                nodes[i]->output->connection = node->inputs[inputIndex];
            }
        }
        lineManager->updateCanvas(nodes[i]);
    }

    box2DManager->updateGroundBody();
}

void CircuitManager::saveFile()
{
    // Opens a window to let the user save their circuit
    QString filepath = QFileDialog::getSaveFileName(levelWidget,
                                                    tr("Choose Circuit"),
                                                    "C://",
                                                    "Circuit Schematic Project (*.csp);;");

    QFile saveFile(filepath);
    if (!saveFile.open(QIODevice::WriteOnly)) {
        QMessageBox::information(levelWidget, tr("Error"), tr("Could not save file :("));
        return;
    }

    QJsonObject levelJSON;
    levelJSON["scale"] = currentZoom;

    QJsonArray nodesJSON;
    for (int i = 0; i < nodes.size(); i++) {
        QJsonObject nodeInfo;

        nodeInfo["name"] = nodes[i]->objectName();
        nodeInfo["x"] = nodes[i]->x();
        nodeInfo["y"] = nodes[i]->y();

        bool isInputNode = nodes[i]->objectName().contains("inputNode");
        nodeInfo["state"] = isInputNode ? nodes[i]->run() : -1;

        QJsonArray inputs;
        for (int inputIndex = 0; inputIndex < nodes[i]->inputs.size(); inputIndex++) {
            QJsonObject inputInfo;

            inputInfo["inputName"] = nodes[i]->inputs[inputIndex]->objectName();
            inputInfo["connection"] = nodes[i]->inputs[inputIndex]->connection
                                          ? nodes[i]->inputs[inputIndex]->connection->objectName()
                                          : "";
            inputInfo["connectionNodeName"]
                = nodes[i]->inputs[inputIndex]->connection
                      ? nodes[i]->inputs[inputIndex]->connection->node->objectName()
                      : "";

            inputs.append(inputInfo);
        }

        nodeInfo["inputs"] = inputs;

        QJsonObject outputInfo;
        if (nodes[i]->output && nodes[i]->output->connection) {
            outputInfo["outputName"] = nodes[i]->output->objectName();
            outputInfo["connection"] = nodes[i]->output->connection->objectName();
            outputInfo["connectionNodeName"] = nodes[i]->output->connection->node->objectName();
        } else {
            outputInfo["outputName"] = "";
            outputInfo["connection"] = "";
            outputInfo["connectionNodeName"] = "";
        }

        nodeInfo["output"] = outputInfo;
        nodesJSON.append(nodeInfo);
    }

    levelJSON["nodes"] = nodesJSON;

    QJsonDocument docJSON(levelJSON);
    saveFile.write(docJSON.toJson());
}

void CircuitManager::runEachOutput()
{
    for (unsigned long i = 0; i < outputNodes.size(); i++) {
        outputNodes[i]->run();
    }
}

void CircuitManager::clearAllNodes()
{
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i--]->deleteNode();
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

    if (nodeToDelete->objectName().contains("outputNode")) {
        outputNodes.erase(std::remove(outputNodes.begin(), outputNodes.end(), nodeToDelete),
                          outputNodes.end());
    }
}

/*    ----    NODE CREATION METHODS   ----    */

void CircuitManager::handleNewNode(CircuitNode *node, QPoint nodePos)
{
    node->drawNode(currentZoom, node->pos());
    levelWidget->layout()->addWidget(node);
    lineManager->createCanvas(node);

    if (nodePos == QPoint()) {
        nodePos = QPoint(10, 30);

        // Finds open position for node.
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->pos() == nodePos) {
                nodePos = QPoint(nodePos.x() + 10, nodePos.y() + 10);
            }
        }
    }

    node->move(nodePos);
    nodes.push_back(node);

    // Node Deleted Connection
    connect(node->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        deleteNode(node);
        box2DManager->nodeDeleted(node);
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
            [=](QPoint parentPos, QPoint slotPos, QPointF offset, QPoint mousePos) {
                // QPoint parentPos, QPoint slotPos, int size, QPoint mousePos)
                lineManager->drawSlotDrag(node, parentPos, slotPos, offset, mousePos);
            });

    // Node Drag Connection
    connect(node->circuitSignalHandler, &CircuitSignalHandler::nodeMoved, this, [=]() {
        lineManager->nodeMoved(node);
        box2DManager->nodeMoved(node);
    });

    connect(node->circuitSignalHandler,
            &CircuitSignalHandler::outputDragConnect,
            this,
            [=](QPoint mousePos) {
                this->mousePos = new QPoint(mousePos.x(), mousePos.y());
                this->currentNode = node;
                inputSlotDrag = false;
                qcOutputBtn->setEnabled(true);
                qcInputBtn->setEnabled(false);
                quickCircuitMenu->move(mousePos - QPoint(10, 10));
                quickCircuitMenu->raise();
                quickCircuitMenu->show();
            });

    connect(node->circuitSignalHandler,
            &CircuitSignalHandler::inputDragConnect,
            this,
            [=](QPoint mousePos, NodeInputSlot *inSlot) {
                this->mousePos = new QPoint(mousePos.x(), mousePos.y());
                this->currentNode = node;
                inputSlotDrag = true;
                draggedInputSlot = inSlot;
                qcOutputBtn->setEnabled(false);
                qcInputBtn->setEnabled(true);
                quickCircuitMenu->move(mousePos - QPoint(10, 10));
                quickCircuitMenu->raise();
                quickCircuitMenu->show();
            });

    box2DManager->addNode(node);
}

/*  ZOOM FUNCTIONS  */

float CircuitManager::clamp(float d, float min, float max)
{
    const float t = d < min ? min : d;
    return t > max ? max : t;
}

void CircuitManager::zoomIn()
{
    currentZoom = clamp(currentZoom + 0.1, 0.4, 1);
    for (CircuitNode *x : nodes) {
        x->drawNode(currentZoom, x->pos());
    }
    for (CircuitNode *x : nodes) {
        lineManager->updateCanvas(x);
    }
    box2DManager->nodesScaled();
}

void CircuitManager::zoomOut()
{
    currentZoom = clamp(currentZoom - 0.1, 0.4, 1);
    for (CircuitNode *x : nodes) {
        x->drawNode(currentZoom, x->pos());
    }
    for (CircuitNode *x : nodes) {
        lineManager->updateCanvas(x);
    }
    box2DManager->nodesScaled();
}
void CircuitManager::zoomCustom(int customZoom)
{
    currentZoom = clamp((float)customZoom / (float)100, 0.4, 1);
    qDebug() << currentZoom;
    for (CircuitNode *x : nodes) {
        x->drawNode(currentZoom, x->pos());
        lineManager->updateCanvas(x);
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

void CircuitManager::createNotGate()
{
    handleNewNode(new NotGate(levelWidget));
}

void CircuitManager::createXNOrGate()
{
    handleNewNode(new XnOrGate(levelWidget));
}

void CircuitManager::createXOrGate()
{
    handleNewNode(new xOrGate(levelWidget));
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
