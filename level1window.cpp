#include "level1window.h"
#include "ui_level1window.h"
#include <QWheelEvent>
#include <iostream>

Level1Window::Level1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    instance = new circuitElementsMenu(this);
    ui->lvlLayout->layout()->addWidget(instance);

}

Level1Window::~Level1Window()
{
    delete ui;
}
float clamp(float d, float min, float max) {
    const float t = d < min ? min : d;
    return t > max ? max : t;
}
void Level1Window::wheelEvent(QWheelEvent *event) {
    // Detect the direction of the mouse wheel movement
    if (event->angleDelta().y() > 0) {
        // Mouse wheel moved up
            //instance->nodes
        for(CircuitNode *x: instance->nodes)
        {
            currentZoom = clamp(currentZoom + 0.1, 0.2, 1);
            x->drawNode(currentZoom, x->pos());
        }
        qDebug() << "Mouse wheel moved up in main window";
    } else {
        // Mouse wheel moved down
        for(CircuitNode *x: instance->nodes)
        {
            currentZoom = clamp(currentZoom - 0.1, 0.2, 1);
            x->drawNode(currentZoom, x->pos());
        }
        qDebug() << "Mouse wheel moved down in main window";
    }
     QMainWindow::wheelEvent(event);
    // You can also access the exact delta value using event->delta()

    // Pass the event to the base class for default handling
}






