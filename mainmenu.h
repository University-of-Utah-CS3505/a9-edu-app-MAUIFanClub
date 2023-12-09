#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "levelsandboxwindow.h"
#include "levelwindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_logicGateLvlsBtn_clicked();

    void on_exampleCircuitsBtn_clicked();

    void on_sandboxLevelButton_clicked();

    void on_allLvlBtn_clicked();

    void on_andOrLvlBtn_clicked();

    void on_andOrNotLvlBtn_clicked();

    void on_andOrNot2LvlBtn_clicked();

    void on_fishLvlBtn_clicked();

    void on_starLvlBtn_clicked();

    void on_xOrLvlBtn_clicked();

    void on_xnOrLvlBtn_clicked();

    void on_XnOrGateLvlBtn_clicked();

    void on_andGateLvlBtn_clicked();

    void on_nAndGateLvlBtn_clicked();

    void on_nOrGateLvlBtn_clicked();

    void on_notGateLvlBtn_clicked();

    void on_orGateLvlBtn_clicked();

    void on_xOrGateLvlBtn_clicked();

private:
    Ui::MainMenu *ui;

    LevelWindow *andGateLvl;
    LevelWindow *nAndGateLvl;
    LevelWindow *orGateLvl;
    LevelWindow *nOrGateLvl;
    LevelWindow *xOrGateLvl;
    LevelWindow *xnOrGateLvl;
    LevelWindow *notGateLvl;

    LevelWindow *allLvl;
    LevelWindow *andOrLvl;
    LevelWindow *andOrNotLvl;
    LevelWindow *andOrNot2Lvl;
    LevelWindow *fishLvl;
    LevelWindow *starLvl;
    LevelWindow *xnOrLvl;
    LevelWindow *xOrLvl;

    LevelSandboxWindow *sandboxWindow = nullptr;
};

#endif // MAINMENU_H
