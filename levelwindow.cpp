#include "levelwindow.h"
#include <QWheelEvent>
#include "ui_levelwindow.h"
#include <iostream>
#include <mainmenu.h>

LevelWindow::LevelWindow(QMainWindow *mainWindow,
                         QString saveFileName,
                         QString levelName,
                         QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level1Window)
{
    this->mainMenu = mainWindow;

    ui->setupUi(this);
    this->setWindowTitle(levelName);

    instance = new circuitElementsMenu(circuitManager, this);

    circuitManager = new CircuitManager(this);
    nodeQuickMenu = new NodeQuickCreateMenu(circuitManager, this);
    instance = new circuitElementsMenu(circuitManager, this);

    zoomWidget = new ZoomWidget(circuitManager, this);
    zoomWidget->move(QPoint(800, 20));

    circuitManager->quickCircuitMenu = nodeQuickMenu;
    circuitManager->qcInputBtn = nodeQuickMenu->inputBtn;
    circuitManager->qcOutputBtn = nodeQuickMenu->outputBtn;

    nodeQuickMenu->hide();

    this->layout()->addWidget(instance);
    this->layout()->addWidget(nodeQuickMenu);
    this->layout()->addWidget(zoomWidget);

    circuitManager->loadFile(saveFileName);

    zoomWidget->updateZoom(circuitManager->currentZoom);

    ui->stopSimBtn->setEnabled(false);

    // Sets background image for the window.
    QPixmap bkgnd(":/menuIcons/menuIcons/GridLight.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
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
    zoomWidget->updateZoom(circuitManager->currentZoom);
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

void LevelWindow::on_startSimBtn_clicked()
{
    ui->startSimBtn->setEnabled(false);
    circuitManager->box2DManager->startWorld();
    ui->stopSimBtn->setEnabled(true);
}

void LevelWindow::on_stopSimBtn_clicked()
{
    ui->stopSimBtn->setEnabled(false);
    circuitManager->box2DManager->stopWorld();
    ui->startSimBtn->setEnabled(true);
    zoomWidget->updateZoom(circuitManager->box2DManager->startZoom);
}
