#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include "Zoomwidget.h"
#include "circuitelementsmenu.h"
#include "circuitmanager.h"
#include "mainwindow.h"
#include "node_classes/andgate.h"
#include "node_classes/inputnode.h"
#include "node_classes/nandgate.h"
#include "node_classes/norgate.h"
#include "node_classes/orgate.h"
#include "node_classes/outputnode.h"
#include "nodequickcreatemenu.h"

namespace Ui {
class Level1Window;
}

class LevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelWindow(QMainWindow *mainWindow,
                         QString saveFileName,
                         QString levelName,
                         QWidget *parent = nullptr);
    ~LevelWindow();
    circuitElementsMenu *instance;

protected:
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionExit_triggered();
    void on_startSimBtn_clicked();
    void on_stopSimBtn_clicked();

private:
    QMainWindow *mainMenu;
    Ui::Level1Window *ui;
    NodeQuickCreateMenu *nodeQuickMenu;
    CircuitManager *circuitManager;
    ZoomWidget *zoomWidget;
};

#endif // LEVELWINDOW_H
