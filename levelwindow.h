#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include "circuitelementsmenu.h"
#include "circuitmanager.h"
#include "mainwindow.h"
#include "node_classes/andgate.h"
#include "node_classes/inputnode.h"
#include "node_classes/nandgate.h"
#include "node_classes/norgate.h"
#include "node_classes/orgate.h"
#include "node_classes/outputnode.h"
#include "levelmanager.h"
#include "zoomwidget.h"

namespace Ui {
class Level1Window;
}

class LevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelWindow(QMainWindow *mainWindow,
                         QString levelName,
                         QMessageBox *lvlInfoPopup = nullptr,
                         QWidget *parent = nullptr);
    ~LevelWindow();

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_actionExit_triggered();

private:
    QMainWindow *mainMenu;
    Ui::Level1Window *ui;
    circuitElementsMenu *instance;
    zoomWidget *zoomWidget;
    levelManager * levelManager;
};

#endif // LEVELWINDOW_H
