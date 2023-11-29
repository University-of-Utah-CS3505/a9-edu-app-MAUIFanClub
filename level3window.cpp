#include "level3window.h"
#include "ui_level3window.h"

Level3Window::Level3Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Level3Window)
{
    ui->setupUi(this);
}

Level3Window::~Level3Window()
{
    delete ui;
}
