#include "level1window.h"
#include "ui_level1window.h"
#include <QWheelEvent>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>

Level1Window::Level1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    instance = new circuitElementsMenu(this);
    ui->lvlLayout->layout()->addWidget(instance);
//    QGraphicsScene* scene = new QGraphicsScene(this);
//    QGraphicsView* view = new QGraphicsView(scene, this);
//    setCentralWidget(view);

}

Level1Window::~Level1Window()
{
    delete ui;
}
float clamp(float d, float min, float max) {
    const float t = d < min ? min : d;
    return t > max ? max : t;
}
int distanceBetweenPoints(QPoint p1, QPoint p2)
{
    //return (((p2.x() - p1.x())*(p2.x() - p1.x()) +((p2.y() - p1.y())*(p2.y() - p1.y())*0.5)
    return std::sqrt(pow(p2.x() - p1.x(), 2) + pow(p2.y() - p1.y(), 2) * 1.0);
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
        //currentZoom = clamp(currentZoom - 0.1, 0.2, 1);
        //ui->lay->resize(ui->lvlLayout->width()*currentZoom, ui->lvlLayout->height()* currentZoom);
         //Mouse wheel moved down
        for(CircuitNode *x: instance->nodes)
        {
            currentZoom = clamp(currentZoom - 0.1, 0.2, 1);
            x->drawNode(currentZoom, x->pos());
        }
//        for(int i = 0; i < instance->nodes.capacity() - 1; i++)
//        {
//            int initialDistance = distanceBetweenPoints(instance->nodes[i]->pos(),instance->nodes[i+1]->pos());
//            int adjustedDistance = initialDistance * currentZoom;
//            int newX =
//            //instance->nodes[i]->pos();
//        }
        qDebug() << "Mouse wheel moved down in main window";
    }
     QMainWindow::wheelEvent(event);
    // You can also access the exact delta value using event->delta()

    // Pass the event to the base class for default handling
}







