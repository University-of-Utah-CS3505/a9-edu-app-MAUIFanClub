#include "level2window.h"
#include "ui_level2window.h"

Level2Window::Level2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level2Window)
{
    ui->setupUi(this);
}

Level2Window::~Level2Window()
{
    delete ui;
}
