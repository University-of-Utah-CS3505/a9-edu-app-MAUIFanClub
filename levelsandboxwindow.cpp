#include "levelsandboxwindow.h"
#include "ui_levelsandboxwindow.h"
#include <Box2D/Box2D.h>

LevelSandboxWindow::LevelSandboxWindow(QMainWindow *mainWindow, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelSandboxWindow)
{
    this->mainMenu = mainWindow;

    ui->setupUi(this);

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

    zoomWidget->updateZoom(circuitManager->currentZoom);

    ui->stopSimBtn->setEnabled(false);

    // Sets background image for the window.
    QPixmap bkgnd(":/menuIcons/menuIcons/GridLight.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
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
    zoomWidget->updateZoom(circuitManager->currentZoom);
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
