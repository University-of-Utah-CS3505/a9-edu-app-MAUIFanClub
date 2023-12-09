#include "levelwindow.h"
#include <QWheelEvent>
#include "ui_levelwindow.h"
#include <iostream>
#include <mainmenu.h>

LevelWindow::LevelWindow(QMainWindow *mainWindow,
                         QString levelName,
                         QMessageBox *lvlInfoPopup,
                         QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level1Window)
{
    this->mainMenu = mainWindow;

    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);

    this->setWindowTitle(levelName);
    circuitManager->loadFile(levelName);
}

LevelWindow::~LevelWindow()
{
    delete ui;
}

void LevelWindow::wheelEvent(QWheelEvent *event)
{
    // Detect the direction of the mouse wheel movement
    if (event->angleDelta().y() > 0) {
        // Mouse wheel moved up
        circuitManager->zoomIn();
    } else {
        //Mouse wheel moved down
        circuitManager->zoomOut();
    }
    QMainWindow::wheelEvent(event);
}

void LevelWindow::on_actionSave_triggered()
{
    circuitManager->saveFile();
}

void LevelWindow::on_actionLoad_triggered()
{
    circuitManager->loadFile();
}

void LevelWindow::on_actionExit_triggered()
{
    mainMenu->show();
    this->close();
}
