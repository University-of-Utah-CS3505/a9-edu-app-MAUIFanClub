#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "level1window.h"
#include "level2window.h"
#include "level3window.h"
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("border-image: url(:/mainMenuBackground/MainMenuBackground.jpg);");
}
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_level1Button_clicked()
{
    Level1Window *x = new Level1Window();
    x->show();
    this->close();
}

void MainMenu::on_level2Button_clicked()
{
    Level2Window *x = new Level2Window();
    x->show();
    this->close();
}

void MainMenu::on_level3Button_clicked()
{
    Level3Window *x = new Level3Window();
    x->show();
    this->close();
}

