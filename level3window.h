#ifndef LEVEL3WINDOW_H
#define LEVEL3WINDOW_H

#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "circuitmanager.h"

namespace Ui {
class Level3Window;
}

class Level3Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level3Window(QWidget *parent = nullptr);
    ~Level3Window();

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:
    Ui::Level3Window *ui;
    circuitElementsMenu *instance;
    CircuitManager *circuitManager;
};

#endif // LEVEL3WINDOW_H
