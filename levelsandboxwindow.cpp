#include "levelsandboxwindow.h"
#include "circuitelementsmenu.h"
#include "ui_levelsandboxwindow.h"

LevelSandboxWindow::LevelSandboxWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LevelSandboxWindow)
{
    ui->setupUi(this);
    CircuitManager *circuitManager = new CircuitManager(this);
    circuitElementsMenu *instance = new circuitElementsMenu(circuitManager, this);
    this->layout()->addWidget(instance);
}

LevelSandboxWindow::~LevelSandboxWindow()
{
    delete ui;
}
