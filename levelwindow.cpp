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
    zoomWidget = new class zoomWidget(this);
    levelManager = new class levelManager(this, zoomWidget);
    instance = new circuitElementsMenu(levelManager->circuitManager, this);
    this->layout()->addWidget(instance);

    this->setWindowTitle(levelName);
    circuitManager->loadFile(levelName);
    this->layout()->addWidget(zoomWidget);
}

LevelWindow::~LevelWindow()
{
    delete ui;
}

void LevelWindow::wheelEvent(QWheelEvent *event)
{
    levelManager->handleZoom(event);
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
