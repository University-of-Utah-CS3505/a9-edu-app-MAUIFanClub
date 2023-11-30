#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InputNode *inputNode1 = new InputNode();
    inputNode1->move(QPoint(inputNode1->x() + 10, inputNode1->y() + 10));

    InputNode *inputNode2 = new InputNode();
    inputNode2->move(QPoint(inputNode2->x() + 10, inputNode2->y() + 215));

    AndGate *andGate = new AndGate();
    andGate->move(QPoint(andGate->x() + 215, andGate->y() + 10));

    OutputNode *outputNode = new OutputNode();
    outputNode->move(QPoint(outputNode->x() + 420, outputNode->y() + 10));

    this->layout()->addWidget(inputNode1);
    this->layout()->addWidget(inputNode2);
    this->layout()->addWidget(andGate);
    this->layout()->addWidget(outputNode);
}

MainWindow::~MainWindow()
{
    delete ui;
}
