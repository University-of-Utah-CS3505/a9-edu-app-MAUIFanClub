#include "level2window.h"
#include "ui_level2window.h"

Level2Window::Level2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level2Window)
{
    ui->setupUi(this);
    zoomWidget = new class zoomWidget(this);
    levelManager = new class levelManager(this, zoomWidget);
    this->layout()->addWidget(zoomWidget);
    instance = new circuitElementsMenu(levelManager->circuitManager, this);
    this->layout()->addWidget(instance);
}

Level2Window::~Level2Window()
{
    delete ui;
}

void Level2Window::wheelEvent(QWheelEvent *event)
{
    levelManager->handleZoom(event);
    QMainWindow::wheelEvent(event);
    // You can also access the exact delta value using event->delta()

    // Pass the event to the base class for default handling
}
