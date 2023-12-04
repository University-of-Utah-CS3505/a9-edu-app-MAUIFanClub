#ifndef LEVEL3WINDOW_H
#define LEVEL3WINDOW_H

#include <QMainWindow>
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

private:
    Ui::Level3Window *ui;
    CircuitManager *circuitManager;
};

#endif // LEVEL3WINDOW_H
