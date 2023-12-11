#include "levelsandboxwindow.h"
#include "ui_levelsandboxwindow.h"
#include <Box2D/Box2D.h>

LevelSandboxWindow::LevelSandboxWindow(QMainWindow *mainWindow, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelSandboxWindow)
{
    this->mainMenu = mainWindow;

    ui->setupUi(this);
    circuitManager = new CircuitManager(this);
    nodeQuickMenu = new NodeQuickCreateMenu(circuitManager, this);
    circuitManager->quickCircuitMenu = nodeQuickMenu;
    instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);
    this->layout()->addWidget(nodeQuickMenu);
    nodeQuickMenu->hide();

    ui->stopSimBtn->setEnabled(false);
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

void LevelSandboxWindow::on_actionExit_triggered()
{
    mainMenu->show();
    this->close();
}

void LevelSandboxWindow::on_startSimBtn_clicked()
{
    ui->startSimBtn->setEnabled(false);
    circuitManager->box2DManager->startWorld();
    ui->stopSimBtn->setEnabled(true);
}

void LevelSandboxWindow::on_stopSimBtn_clicked()
{
    ui->stopSimBtn->setEnabled(false);
    circuitManager->box2DManager->stopWorld();
    ui->startSimBtn->setEnabled(true);
}
