#ifndef CIRCUITMANAGER_H
#define CIRCUITMANAGER_H

#include <QApplication>
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

    vector<CircuitNode *> nodes;
    vector<OutputNode *> outputNodes;

    void run();
    void runEachOutput();
    bool isGraphCompleted();

    void deleteNode(CircuitNode *nodeToDelete);

    void createAndGate();
    void createNAndGate();
    void createOrGate();
    void createNOrGate();
    void createInputNode();
    void createOutputNode();

private:
    NodeLineConnectionManager *lineManager;
    void handleNewNode(CircuitNode *node);
};

#endif // CIRCUITMANAGER_H
