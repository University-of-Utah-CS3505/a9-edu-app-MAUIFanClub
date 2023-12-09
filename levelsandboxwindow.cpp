#include "levelsandboxwindow.h"
#include "ui_levelsandboxwindow.h"

LevelSandboxWindow::LevelSandboxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelSandboxWindow)
{
    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);

    //connect(ui->menuSave, SIGNAL(aboutToShow()), this, SLOT(help()));
}

LevelSandboxWindow::~LevelSandboxWindow()
{
    delete ui;
}

void LevelSandboxWindow::wheelEvent(QWheelEvent *event)
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

void LevelSandboxWindow::on_actionSave_triggered()
{
    circuitManager->saveFile();
}

void LevelSandboxWindow::on_actionLoad_triggered()
{
    circuitManager->loadFile();
}
