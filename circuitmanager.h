#ifndef CIRCUITMANAGER_H
#define CIRCUITMANAGER_H

#include <QApplication>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLayout>
#include <QMessageBox>
#include <QWidget>
#include <vector>

#include "node_classes/andgate.h"
#include "node_classes/circuitnode.h"
#include "node_classes/circuitsignalhandler.h"
#include "node_classes/inputnode.h"
#include "node_classes/nandgate.h"
#include "node_classes/nodelineconnectionmanager.h"
#include "node_classes/norgate.h"
#include "node_classes/orgate.h"
#include "node_classes/outputnode.h"

using std::vector;

class CircuitManager : QObject
{
public:
    CircuitManager(QWidget *levelWidget);

    QWidget *levelWidget;

    float currentZoom = 1;

    float clamp(float d, float min, float max);

    int *nodeCount;
    int *inputCount;
    int *outputCount;

    vector<CircuitNode *> nodes;
    vector<OutputNode *> outputNodes;

    void run();
    void runEachOutput();
    bool isGraphCompleted();

    void loadFile();
    void saveFile();

    void deleteNode(CircuitNode *nodeToDelete);
    void clearAllNodes();

    void zoomIn();
    void zoomOut();

    void createAndGate();
    void createNAndGate();
    void createOrGate();
    void createNOrGate();
    void createInputNode();
    void createOutputNode();

private:
    NodeLineConnectionManager *lineManager;
    void handleNewNode(CircuitNode *node, QPoint nodePos = QPoint());
};

#endif // CIRCUITMANAGER_H
