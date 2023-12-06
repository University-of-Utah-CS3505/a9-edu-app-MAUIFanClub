#include "level3window.h"
#include "ui_level3window.h"

Level3Window::Level3Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level3Window)
{
    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);
}

Level3Window::~Level3Window()
{
    delete ui;
}

void Level3Window::wheelEvent(QWheelEvent *event)
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
