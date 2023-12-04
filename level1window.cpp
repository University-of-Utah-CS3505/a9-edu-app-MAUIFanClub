#include "level1window.h"
#include "circuitelementsmenu.h"
#include "ui_level1window.h"

Level1Window::Level1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    CircuitManager *circuitManager = new CircuitManager(this);
    circuitElementsMenu *instance = new circuitElementsMenu(circuitManager, this);
    ui->lvlLayout->layout()->addWidget(instance);
}

Level1Window::~Level1Window()
{
    delete ui;
}




