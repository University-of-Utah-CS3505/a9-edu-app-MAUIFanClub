#ifndef CIRCUITELEMENTSMENU_H
#define CIRCUITELEMENTSMENU_H
#include <vector>
#include <QWidget>

namespace Ui {
class circuitElementsMenu;
}

class circuitElementsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit circuitElementsMenu(QWidget *parent = nullptr);
    ~circuitElementsMenu();

private slots:
    void on_CircuitElementsButton_clicked();

    void on_logicGatesButton_clicked();

    void on_inputsButton_clicked();

private:
    Ui::circuitElementsMenu *ui;
    //QWidget* allElementGrids[5];
    std::vector <QWidget*> x;
};

#endif // CIRCUITELEMENTSMENU_H
