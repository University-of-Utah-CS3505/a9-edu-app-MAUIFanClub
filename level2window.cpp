#include "level2window.h"
#include "ui_level2window.h"

Level2Window::Level2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level2Window)
{
    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);
}

Level2Window::~Level2Window()
{
    delete ui;
}

void Level2Window::wheelEvent(QWheelEvent *event)
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
    // You can also access the exact delta value using event->delta()

    // Pass the event to the base class for default handling
}
