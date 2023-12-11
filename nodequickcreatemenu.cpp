#include "nodequickcreatemenu.h"
#include "ui_nodequickcreatemenu.h"

NodeQuickCreateMenu::NodeQuickCreateMenu(CircuitManager *circuitManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NodeQuickCreateMenu)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->circuitManager = circuitManager;
    this->currentNode = circuitManager->currentNode;

    inputBtn = ui->qcInputBtn;
    outputBtn = ui->qcOutputBtn;
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

void NodeQuickCreateMenu::on_qcInputBtn_clicked()
{
    circuitManager->createInputNode();
    updateNewNode();
}

void NodeQuickCreateMenu::updateNewNode()
{
    if (circuitManager->inputSlotDrag) {
        CircuitNode *newNode = circuitManager->nodes[circuitManager->nodes.size() - 1];
        NodeOutputSlot *outSlot = newNode->output;
        NodeInputSlot *inSlot = circuitManager->draggedInputSlot;

        // Node position based off output slot
        newNode->move((*circuitManager->mousePos) - outSlot->pos()
                      - QPoint(outSlot->currentSize / 2, outSlot->currentSize / 2));

        // Node position based off middle of node
        //        newNode->move((*circuitManager->mousePos)
        //                      - QPoint(newNode->nodeSize / 2, newNode->nodeSize / 2));

        outSlot->connection = inSlot;
        inSlot->connection = outSlot;

        circuitManager->lineManager->updateCanvas(newNode);
    } else {
        CircuitNode *newNode = circuitManager->nodes[circuitManager->nodes.size() - 1];
        NodeInputSlot *inSlot = newNode->inputs[0];

        // Node position based off input slot pos
        newNode->move((*circuitManager->mousePos) - inSlot->pos()
                      - QPoint(inSlot->currentSize / 2, inSlot->currentSize / 2));

        // Node position based off middle of node
        //        newNode->move((*circuitManager->mousePos)
        //                      - QPoint(newNode->nodeSize / 2, newNode->nodeSize / 2));

        inSlot->connection = circuitManager->currentNode->output;
        circuitManager->currentNode->output->connection = inSlot;

        circuitManager->lineManager->updateCanvas(circuitManager->currentNode);
    }

    this->hide();
}

void NodeQuickCreateMenu::mouseMoveEvent(QMouseEvent *event)
{
    // Used to place new node on the overall mouse position. Instead of mouse release pos.
    //*circuitManager->mousePos = event->scenePosition().toPoint();
}

void NodeQuickCreateMenu::leaveEvent(QEvent *event)
{
    this->hide();
    QWidget::leaveEvent(event);
}
