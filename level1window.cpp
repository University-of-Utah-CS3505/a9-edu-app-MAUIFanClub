#include "level1window.h"
#include <QWheelEvent>
#include "ui_level1window.h"
#include <iostream>
Level1Window::Level1Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    zoomWidget = new class zoomWidget(this);
    levelManager = new class levelManager(this, zoomWidget);
    instance = new circuitElementsMenu(levelManager->circuitManager, this);
    this->layout()->addWidget(instance);
    this->layout()->addWidget(zoomWidget);
    //ui->zoomWidget->layout()->addWidget(zoomWidget);
   // ui->zoomWidget->layout()->addWidget(zoomWidget);

}

Level1Window::~Level1Window()
{
    delete ui;
}

void Level1Window::wheelEvent(QWheelEvent *event)
{
    levelManager->handleZoom(event);
    QMainWindow::wheelEvent(event);
}
