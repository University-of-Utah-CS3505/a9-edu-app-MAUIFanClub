#include "level1window.h"
#include <QWheelEvent>
#include "ui_level1window.h"
#include <iostream>

Level1Window::Level1Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);
}

Level1Window::~Level1Window()
{
    delete ui;
}

void Level1Window::wheelEvent(QWheelEvent *event)
{
    // Detect the direction of the mouse wheel movement
    if (event->angleDelta().y() > 0) {
        // Mouse wheel moved up
        circuitManager->zoomIn();
    } else {
        //Mouse wheel moved down
        circuitManager->zoomOut();
    }
    QMainWindow::wheelEvent(event);
}

void Level1Window::on_actionSave_triggered()
{
    circuitManager->saveFile();
}

void Level1Window::on_actionLoad_triggered()
{
    circuitManager->loadFile();
}
