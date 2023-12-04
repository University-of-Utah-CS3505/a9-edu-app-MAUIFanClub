#ifndef LEVEL1WINDOW_H
#define LEVEL1WINDOW_H

#include <QMainWindow>
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

private slots:

private:
    Ui::Level1Window *ui;
    CircuitManager *circuitManager;
};

#endif // LEVEL1WINDOW_H
