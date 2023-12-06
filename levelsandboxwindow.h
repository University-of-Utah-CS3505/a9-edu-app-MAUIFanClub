#ifndef LEVELSANDBOXWINDOW_H
#define LEVELSANDBOXWINDOW_H

#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "circuitmanager.h"

namespace Ui {
class LevelSandboxWindow;
}

class LevelSandboxWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelSandboxWindow(QWidget *parent = nullptr);
    ~LevelSandboxWindow();

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::LevelSandboxWindow *ui;
    circuitElementsMenu *instance;
    CircuitManager *circuitManager;
};

#endif // LEVELSANDBOXWINDOW_H
