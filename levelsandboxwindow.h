#ifndef LEVELSANDBOXWINDOW_H
#define LEVELSANDBOXWINDOW_H

#include <QMainWindow>
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

private:
    Ui::LevelSandboxWindow *ui;
    CircuitManager *circuitManager;
};

#endif // LEVELSANDBOXWINDOW_H
