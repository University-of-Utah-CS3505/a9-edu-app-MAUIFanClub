#ifndef LEVEL1WINDOW_H
#define LEVEL1WINDOW_H
#include <QDebug>
#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "node_classes/andgate.h"
#include "node_classes/inputnode.h"
#include "node_classes/nandgate.h"
#include "node_classes/norgate.h"
#include "node_classes/orgate.h"
#include "node_classes/outputnode.h"
#include "circuitmanager.h"

namespace Ui {
class Level1Window;
}

class Level1Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level1Window(QWidget *parent = nullptr);
    ~Level1Window();

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:

private:
    Ui::Level1Window *ui;
    circuitElementsMenu *instance;
    float currentZoom = 1;
    CircuitManager *circuitManager;
};

#endif // LEVEL1WINDOW_H
