#ifndef LEVEL2WINDOW_H
#define LEVEL2WINDOW_H

#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "circuitmanager.h"

namespace Ui {
class Level2Window;
}

class Level2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level2Window(QWidget *parent = nullptr);
    ~Level2Window();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::Level2Window *ui;
    circuitElementsMenu *instance;
    CircuitManager *circuitManager;
};

#endif // LEVEL2WINDOW_H
