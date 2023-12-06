#ifndef LEVEL3WINDOW_H
#define LEVEL3WINDOW_H

#include <QMainWindow>
#include "circuitelementsmenu.h"
#include "levelmanager.h"
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

private:
    Ui::Level3Window *ui;
    circuitElementsMenu *instance;
    levelManager * levelManager;
};

#endif // LEVEL3WINDOW_H
