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
    explicit LevelSandboxWindow(QMainWindow *mainWindow, QWidget *parent = nullptr);
    ~LevelSandboxWindow();

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionExit_triggered();

private:
    QMainWindow *mainMenu;
    Ui::LevelSandboxWindow *ui;
    circuitElementsMenu *instance;
    CircuitManager *circuitManager;
};

#endif // LEVELSANDBOXWINDOW_H
