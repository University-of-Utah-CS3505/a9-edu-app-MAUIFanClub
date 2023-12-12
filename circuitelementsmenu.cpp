#include "circuitelementsmenu.h"
#include "ui_circuitelementsmenu.h"

circuitElementsMenu::circuitElementsMenu(CircuitManager *circuitManager, QWidget *parent)
    : circuitManager(circuitManager)
    , ui(new Ui::circuitElementsMenu)
{
    ui->setupUi(this);

    ui->logicGatesGrid->setHidden(true);
    ui->inputsGrid->setHidden(true);

    this->move(QPoint(20, 200));

    ui->ElementsLayout->layout()->setContentsMargins(QMargins(0,0,0,0));
    ui->ElementsLayout->layout()->setSpacing(0);
    levelWidget = parent;
    raise();
}

circuitElementsMenu::~circuitElementsMenu()
{
    delete ui;
}

void circuitElementsMenu::on_CircuitElementsButton_clicked()
{
    ui->elementsList->setHidden(!ui->elementsList->isHidden());
}

void circuitElementsMenu::on_logicGatesButton_clicked()
{
    ui->logicGatesGrid->setHidden(!ui->logicGatesGrid->isHidden());
}

void circuitElementsMenu::on_inputsButton_clicked()
{
    ui->inputsGrid->setHidden(!ui->inputsGrid->isHidden());
}

void circuitElementsMenu::on_clearBtn_clicked()
{
	circuitManager->clearAllNodes();
}

void circuitElementsMenu::on_andGateBtn_clicked()
{
    circuitManager->createAndGate();
}

void circuitElementsMenu::on_orGateBtn_clicked()
{
    circuitManager->createOrGate();
}

void circuitElementsMenu::on_nandGateBtn_clicked()
{
    circuitManager->createNAndGate();
}

void circuitElementsMenu::on_norGateBtn_clicked()
{
    circuitManager->createNOrGate();
}

void circuitElementsMenu::on_newInputBtn_clicked()
{
    circuitManager->createInputNode();
}

void circuitElementsMenu::on_newOutputBtn_clicked()
{
    circuitManager->createOutputNode();
}

void circuitElementsMenu::on_notGateBtn_clicked()
{
    circuitManager->createNotGate();
}

void circuitElementsMenu::on_xnOrGateBtn_clicked()
{
    circuitManager->createXNOrGate();
}

void circuitElementsMenu::on_xOrGateBtn_clicked()
{
    circuitManager->createXOrGate();
}

void circuitElementsMenu::on_runBtn_clicked()
{
    circuitManager->run();
}
