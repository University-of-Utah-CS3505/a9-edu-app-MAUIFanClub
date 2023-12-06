#ifndef LEVEL1WINDOW_H
#define LEVEL1WINDOW_H
#include <QDebug>
#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "levelmanager.h"
#include "zoomwidget.h"

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
    zoomWidget *zoomWidget;
    levelManager * levelManager;
};

#endif // LEVEL1WINDOW_H
