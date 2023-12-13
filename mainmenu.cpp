#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet(
        "border-image: url(:/mainMenuBackground/MainMenuBackground.jpg);");

    ui->mmLogicGateLvlBtns->hide();
    ui->mmCircuitExampleBtn->hide();

    andGateLvl = new LevelWindow(this, "and_d");
    nAndGateLvl = new LevelWindow(this, "nand_d");
    orGateLvl = new LevelWindow(this, "or_d");
    nOrGateLvl = new LevelWindow(this, "nor_d");
    xOrGateLvl = new LevelWindow(this, "xor_d");
    xnOrGateLvl = new LevelWindow(this, "xnor_d");
    notGateLvl = new LevelWindow(this, "not_d");

    allLvl = new LevelWindow(this, "all_1");
    andOrLvl = new LevelWindow(this, "andor_1");
    andOrNotLvl = new LevelWindow(this, "andornot_1");
    andOrNot2Lvl = new LevelWindow(this, "andornot_2");
    fishLvl = new LevelWindow(this, "level_fish");
    starLvl = new LevelWindow(this, "level_star");
    xnOrLvl = new LevelWindow(this, "xnor_2");
    xOrLvl = new LevelWindow(this, "xor_2");

    sandboxWindow = new LevelSandboxWindow(this);
}
MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_logicGateLvlsBtn_clicked()
{
    if (ui->mmLogicGateLvlBtns->isHidden()) {
        if (!ui->mmCircuitExampleBtn->isHidden()) {
            ui->mmCircuitExampleBtn->hide();
        }

        ui->mmLogicGateLvlBtns->show();
    } else {
        ui->mmLogicGateLvlBtns->hide();
    }
}

void MainMenu::on_exampleCircuitsBtn_clicked()
{
    if (ui->mmCircuitExampleBtn->isHidden()) {
        if (!ui->mmLogicGateLvlBtns->isHidden()) {
            ui->mmLogicGateLvlBtns->hide();
        }

        ui->mmCircuitExampleBtn->show();
    } else {
        ui->mmCircuitExampleBtn->hide();
    }
}

void MainMenu::on_sandboxLevelButton_clicked()
{
    sandboxWindow->show();
    this->close();
}

void MainMenu::on_allLvlBtn_clicked()
{
    allLvl->show();
    this->close();
}

void MainMenu::on_andOrLvlBtn_clicked()
{
    andOrLvl->show();
    this->close();
}

void MainMenu::on_andOrNotLvlBtn_clicked()
{
    andOrNotLvl->show();
    this->close();
}

void MainMenu::on_andOrNot2LvlBtn_clicked()
{
    andOrNot2Lvl->show();
    this->close();
}

void MainMenu::on_fishLvlBtn_clicked()
{
    fishLvl->show();
    this->close();
}

void MainMenu::on_starLvlBtn_clicked()
{
    starLvl->show();
    this->close();
}

void MainMenu::on_xOrLvlBtn_clicked()
{
    xOrLvl->show();
    this->close();
}

void MainMenu::on_xnOrLvlBtn_clicked()
{
    xnOrLvl->show();
    this->close();
}

void MainMenu::on_XnOrGateLvlBtn_clicked()
{
    xnOrGateLvl->show();
    QMessageBox::information(xnOrGateLvl,
                             tr("XNOR Gate"),
                             tr("").append(andGateLvl->instance->xnOrGateInfo));
    this->close();
}

void MainMenu::on_andGateLvlBtn_clicked()
{
    andGateLvl->show();
    QMessageBox::information(andGateLvl,
                             tr("AND Gate"),
                             tr("").append(andGateLvl->instance->andGateInfo));
    this->close();
}

void MainMenu::on_nAndGateLvlBtn_clicked()
{
    nAndGateLvl->show();
    QMessageBox::information(nAndGateLvl,
                             tr("NAND Gate"),
                             tr("").append(andGateLvl->instance->nAndGateInfo));
    this->close();
}

void MainMenu::on_nOrGateLvlBtn_clicked()
{
    nOrGateLvl->show();
    QMessageBox::information(nOrGateLvl,
                             tr("NOR Gate"),
                             tr("").append(andGateLvl->instance->nOrGateInfo));
    this->close();
}

void MainMenu::on_notGateLvlBtn_clicked()
{
    notGateLvl->show();
    QMessageBox::information(notGateLvl,
                             tr("NOT Gate"),
                             tr("").append(andGateLvl->instance->notGateInfo));
    this->close();
}

void MainMenu::on_orGateLvlBtn_clicked()
{
    orGateLvl->show();
    QMessageBox::information(orGateLvl,
                             tr("OR Gate"),
                             tr("").append(andGateLvl->instance->orGateInfo));
    this->close();
}

void MainMenu::on_xOrGateLvlBtn_clicked()
{
    xOrGateLvl->show();
    QMessageBox::information(xOrGateLvl,
                             tr("XOR Gate"),
                             tr("").append(andGateLvl->instance->xOrGateInfo));
    this->close();
}
