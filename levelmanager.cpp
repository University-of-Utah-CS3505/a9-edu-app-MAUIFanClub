#include "levelmanager.h"

levelManager::levelManager(QMainWindow * levelWindow, class zoomWidget* zoomWidget, QObject *parent) : QObject(parent)
{
    this->levelWindow = levelWindow;
    this->zoomWidget = zoomWidget;
    circuitManager = new CircuitManager(levelWindow);
    // connect(zoomWidget, SIGNAL(barChanged(int)), circuitManager, SLOT(zoomCustom(int)));
    connect(zoomWidget, &zoomWidget::barChanged ,circuitManager, &CircuitManager::zoomCustom);
}
float linearScale(float originalValue, float minOriginal, float maxOriginal, float minScaled, float maxScaled)
{
    return ((originalValue - minOriginal) / (maxOriginal - minOriginal)) * (maxScaled - minScaled) + minScaled ;
}
void levelManager::handleZoom(QWheelEvent *event)
{
    zoomWidget->updateZoom(linearScale(circuitManager->currentZoom * 100, 40,100,0,100));
    // Detect the direction of the mouse wheel movement
    if (event->angleDelta().y() > 0) {
        // Mouse wheel moved up
        circuitManager->zoomIn();
    } else {
        //Mouse wheel moved down
        circuitManager->zoomOut();
    }
}

