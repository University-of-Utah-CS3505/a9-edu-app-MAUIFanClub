#include "level2window.h"
#include "circuitelementsmenu.h"
#include "ui_level2window.h"

Level2Window::Level2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level2Window)
{
    ui->setupUi(this);
    circuitElementsMenu *instance = new circuitElementsMenu(this);
    ui->lvlLayout->layout()->addWidget(instance);
}

Level2Window::~Level2Window()
{
    delete ui;
}
