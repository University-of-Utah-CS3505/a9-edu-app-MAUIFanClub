#include "level3window.h"
#include "ui_level3window.h"

Level3Window::Level3Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level3Window)
{
    ui->setupUi(this);
   // levelManager = new class levelManager(this);
   // instance = new circuitElementsMenu(levelManager->circuitManager, this);
    this->layout()->addWidget(instance);
}

Level3Window::~Level3Window()
{
    delete ui;
}

void Level3Window::wheelEvent(QWheelEvent *event)
{
    // Detect the direction of the mouse wheel movement
    //levelManager->handleZoom(event);
    QMainWindow::wheelEvent(event);
    // You can also access the exact delta value using event->delta()
    // Pass the event to the base class for default handling
}
