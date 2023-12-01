#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InputNode *inputNode1 = new InputNode(this);
    inputNode1->move(QPoint(inputNode1->x() + 10, inputNode1->y() + 10));

    InputNode *inputNode2 = new InputNode(this);
    inputNode2->move(QPoint(inputNode2->x() + 10, inputNode2->y() + 215));

    AndGate *andGate = new AndGate(this);
    andGate->move(QPoint(andGate->x() + 215, andGate->y() + 10));

    OrGate *orGate = new OrGate(this);
    orGate->move(QPoint(orGate->x() + 215, orGate->y() + 215));

    outputNode = new OutputNode(this);
    outputNode->move(QPoint(outputNode->x() + 420, outputNode->y() + 10));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_runBtn_clicked()
{
    outputNode->run();
}
