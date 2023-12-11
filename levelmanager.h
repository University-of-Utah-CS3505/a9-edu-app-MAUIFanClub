#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include "QWheelEvent"
#include "circuitmanager.h"
#include <QMainWindow>
#include <QObject>
#include "zoomwidget.h"
class levelManager : public QObject
{
    Q_OBJECT
public:
    levelManager(QMainWindow *levelWindow, ZoomWidget *zoomWidget, QObject *parent = nullptr);
    void handleZoom(QWheelEvent *event);
    CircuitManager *circuitManager;
private:
    QMainWindow * levelWindow;
    //ZoomWidget* zoomWidget;
private slots:
    //void zoomWidgetCustomVal(int val);
};

#endif // LEVELMANAGER_H
