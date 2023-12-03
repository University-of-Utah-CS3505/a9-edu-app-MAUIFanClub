#include "circuitelementsmenu.h"
#include "ui_circuitelementsmenu.h"

circuitElementsMenu::circuitElementsMenu(QWidget *parent)
    : ui(new Ui::circuitElementsMenu)
{
    ui->setupUi(this);
    x.push_back(ui->inputsGrid);
    x.push_back(ui->logicGatesGrid);

    for (QWidget *currentWidget : x) {
        currentWidget->setHidden(true);
    }

    levelWidget = parent;
    raise();
}

circuitElementsMenu::~circuitElementsMenu()
{
    delete ui;
}

void circuitElementsMenu::on_CircuitElementsButton_clicked()
{
    if (!ui->elementsList->isHidden()) {
        ui->elementsList->setHidden(true);
    } else {
        ui->elementsList->setHidden(false);
    }
}

void circuitElementsMenu::on_logicGatesButton_clicked()
{
    if (!ui->logicGatesGrid->isHidden()) {
        ui->logicGatesGrid->setHidden(true);
    } else {
        for (QWidget *currentWidget : x) {
            currentWidget->setHidden(true);
        }
        ui->logicGatesGrid->setHidden(false);
    }
}

void circuitElementsMenu::on_inputsButton_clicked()
{
    if (!ui->inputsGrid->isHidden()) {
        ui->inputsGrid->setHidden(true);
    } else {
        for (QWidget *currentWidget : x) {
            currentWidget->setHidden(true);
        }
        ui->inputsGrid->setHidden(false);
    }
}

void circuitElementsMenu::on_andGateBtn_clicked()
{
    AndGate *andGateNode = new AndGate(levelWidget);
    levelWidget->layout()->addWidget(andGateNode);
    andGateNode->move(QPoint(andGateNode->x() + 10, andGateNode->y() + 10));

    nodes.push_back(andGateNode);
    connect(andGateNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(andGateNode);
    });
}

void circuitElementsMenu::on_orGateBtn_clicked()
{
    OrGate *orGateNode = new OrGate(levelWidget);
    levelWidget->layout()->addWidget(orGateNode);
    orGateNode->move(QPoint(orGateNode->x() + 10, orGateNode->y() + 10));

    nodes.push_back(orGateNode);
    connect(orGateNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(orGateNode);
    });
}

void circuitElementsMenu::on_nandGateBtn_clicked()
{
    nAndGate *nAndGateNode = new nAndGate(levelWidget);
    levelWidget->layout()->addWidget(nAndGateNode);
    nAndGateNode->move(QPoint(nAndGateNode->x() + 10, nAndGateNode->y() + 10));

    nodes.push_back(nAndGateNode);
    connect(nAndGateNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(nAndGateNode);
    });
}

void circuitElementsMenu::on_norGateBtn_clicked()
{
    nOrGate *nOrGateNode = new nOrGate(levelWidget);
    levelWidget->layout()->addWidget(nOrGateNode);
    nOrGateNode->move(QPoint(nOrGateNode->x() + 10, nOrGateNode->y() + 10));

    nodes.push_back(nOrGateNode);
    connect(nOrGateNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(nOrGateNode);
    });
}

void circuitElementsMenu::on_newInputBtn_clicked()
{
    InputNode *inputNode = new InputNode(levelWidget);
    levelWidget->layout()->addWidget(inputNode);
    inputNode->move(QPoint(inputNode->x() + 10, inputNode->y() + 10));

    nodes.push_back(inputNode);
    connect(inputNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(inputNode);
    });
}

void circuitElementsMenu::on_newOutputBtn_clicked()
{
    OutputNode *outputNode = new OutputNode(levelWidget);
    levelWidget->layout()->addWidget(outputNode);
    outputNode->move(QPoint(outputNode->x() + 10, outputNode->y() + 10));

    nodes.push_back(outputNode);
    outputNodes.push_back(outputNode);
    connect(outputNode->circuitSignalHandler, &CircuitSignalHandler::nodeDeleted, this, [=]() {
        nodeDeleted(outputNode);
    });
}

void circuitElementsMenu::on_runBtn_clicked()
{
    if (nodes.size() == 0) {
        QMessageBox::information(this, tr("Error"), tr("THERE ARE NO NODES!"));
        return;
    }

    if (isGraphCompleted()) {
        runEachOutput();
    } else {
        QMessageBox::information(this,
                                 tr("Error"),
                                 tr("GRAPH IS NOT COMPLETED! \n\n - Right Click To Delete Nodes"));
    }
}

void circuitElementsMenu::on_clearBtn_clicked()
{
	for (auto currentNode : nodes) {
		currentNode->deleteNode();
	}
}

// Checks to see if the graph is fully filled out. Each slot has a connection of some sort.
bool circuitElementsMenu::isGraphCompleted()
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

void circuitElementsMenu::nodeDeleted(CircuitNode *deletedNode)
{
	nodes.erase(std::remove(nodes.begin(), nodes.end(), deletedNode), nodes.end());

	if (deletedNode->objectName() == "outputNode") {
		outputNodes.erase(std::remove(nodes.begin(), nodes.end(), deletedNode), nodes.end());
	}
}

void circuitElementsMenu::runEachOutput()
{
	for (unsigned long i = 0; i < outputNodes.size(); i++) {
		outputNodes[i]->run();
	}
}
