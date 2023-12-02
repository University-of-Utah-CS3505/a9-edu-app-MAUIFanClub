#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InputNode *inputNode1 = new InputNode(this);
    inputNode1->move(QPoint(inputNode1->x() + 10, inputNode1->y() + 10));
    nodes.push_back(inputNode1);
    connect(inputNode1->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(inputNode1);
    });

    InputNode *inputNode2 = new InputNode(this);
    inputNode2->move(QPoint(inputNode2->x() + 10, inputNode2->y() + 215));
    nodes.push_back(inputNode2);
    connect(inputNode2->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(inputNode2);
    });

    InputNode *inputNode3 = new InputNode(this);
    inputNode3->move(QPoint(inputNode3->x() + 10, inputNode3->y() + 420));
    nodes.push_back(inputNode3);
    connect(inputNode3->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(inputNode3);
    });

    AndGate *andGate = new AndGate(this);
    andGate->move(QPoint(andGate->x() + 215, andGate->y() + 10));
    nodes.push_back(andGate);
    connect(andGate->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(andGate);
    });

    OrGate *orGate = new OrGate(this);
    orGate->move(QPoint(orGate->x() + 215, orGate->y() + 215));
    nodes.push_back(orGate);
    connect(orGate->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(orGate);
    });

    outputNode = new OutputNode(this);
    outputNode->move(QPoint(outputNode->x() + 420, outputNode->y() + 10));
    nodes.push_back(outputNode);
    connect(outputNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(outputNode);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runBtn_clicked()
{
    if (nodes.size() == 0) {
        QMessageBox::information(this, tr("Error"), tr("THERE ARE NO NODES!"));
        return;
    }

    if (isGraphCompleted()) {
        outputNode->run();
    } else {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("GRAPH IS NOT COMPLETED! \n\n - Right Click To Delete Nodes"));
    }
}

// Checks to see if the graph is fully filled out. Each slot has a connection of some sort.
bool MainWindow::isGraphCompleted()
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

void MainWindow::nodeDeleted(CircuitNode *deletedNode)
{
    nodes.erase(std::remove(nodes.begin(), nodes.end(), deletedNode), nodes.end());
}
