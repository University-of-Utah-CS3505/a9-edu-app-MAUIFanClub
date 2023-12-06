#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

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

    void on_level1Button_clicked();

    void on_level2Button_clicked();

    void on_level3Button_clicked();

    void on_sandboxLevelButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
