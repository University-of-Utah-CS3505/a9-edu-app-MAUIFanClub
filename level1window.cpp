#include "level1window.h"
#include "ui_level1window.h"
#include "circuitelementsmenu.h"

Level1Window::Level1Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level1Window)
{
    ui->setupUi(this);
    circuitElementsMenu * instance = new circuitElementsMenu();
    //this->layout()->addWidget(instance);
    ui->testlay->layout()->addWidget(instance);

}

Level1Window::~Level1Window()
{
    delete ui;
}




