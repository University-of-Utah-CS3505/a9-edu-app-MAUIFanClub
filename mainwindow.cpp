#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AndGate *andGate1 = new AndGate();

    AndGate *andGate2 = new AndGate();
    andGate2->move(QPoint(andGate2->x(), andGate2->y() + 205));

    AndGate *andGate3 = new AndGate();
    andGate3->move(QPoint(andGate3->x(), andGate3->y() + 410));

    this->layout()->addWidget(andGate1);
    this->layout()->addWidget(andGate2);
    this->layout()->addWidget(andGate3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
