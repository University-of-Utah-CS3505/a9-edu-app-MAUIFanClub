#include "nodequickcreatemenu.h"
#include "ui_nodequickcreatemenu.h"

NodeQuickCreateMenu::NodeQuickCreateMenu(CircuitManager *circuitManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NodeQuickCreateMenu)
{
    ui->setupUi(this);
    this->circuitManager = circuitManager;
    this->mousePos = circuitManager->mousePos;
    this->currentNode = circuitManager->currentNode;
}

NodeQuickCreateMenu::~NodeQuickCreateMenu()
{
    delete ui;
}

void NodeQuickCreateMenu::on_andBtn_clicked()
{
    circuitManager->createAndGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_nAndBtn_clicked()
{
    circuitManager->createNAndGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_orBtn_clicked()
{
    circuitManager->createOrGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_nOrBtn_clicked()
{
    circuitManager->createNOrGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_xOrBtn_clicked()
{
    circuitManager->createXOrGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_xnOrBtn_clicked()
{
    circuitManager->createXNOrGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_qtNotBtn_clicked()
{
    circuitManager->createNotGate();
    updateNewNode();
}

void NodeQuickCreateMenu::on_qcOutputBtn_clicked()
{
    circuitManager->createOutputNode();
    updateNewNode();
}

void NodeQuickCreateMenu::updateNewNode()
{
    CircuitNode *newNode = circuitManager->nodes[circuitManager->nodes.size() - 1];
    NodeInputSlot *inSlot = newNode->inputs[0];

    newNode->move((*circuitManager->mousePos) - inSlot->position
                  - QPoint(inSlot->size / 2, inSlot->size / 2));

    inSlot->connection = circuitManager->currentNode->output;
    circuitManager->currentNode->output->connection = inSlot;

    circuitManager->lineManager->updateCanvas(circuitManager->currentNode);
    this->hide();
}
