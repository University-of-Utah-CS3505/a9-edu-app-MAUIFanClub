#ifndef LEVEL2WINDOW_H
#define LEVEL2WINDOW_H

#include <QMainWindow>
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

private:
    Ui::Level2Window *ui;
    CircuitManager *circuitManager;
};

#endif // LEVEL2WINDOW_H
