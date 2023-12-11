#ifndef CIRCUITELEMENTSMENU_H
#define CIRCUITELEMENTSMENU_H

#include <QLayout>
#include <QWidget>
#include "circuitmanager.h"
#include "dragablewidget.h"
#include <vector>

namespace Ui {
class circuitElementsMenu;
}

class circuitElementsMenu : public DragableWidget
{
    Q_OBJECT

public:
    explicit circuitElementsMenu(CircuitManager *circuitManager, QWidget *parent = nullptr);
    ~circuitElementsMenu();

    CircuitManager *circuitManager;

private slots:
    // Button Slots
    void on_CircuitElementsButton_clicked();
    void on_logicGatesButton_clicked();
    void on_inputsButton_clicked();
    void on_andGateBtn_clicked();
    void on_orGateBtn_clicked();
    void on_nandGateBtn_clicked();
    void on_norGateBtn_clicked();
    void on_newInputBtn_clicked();
	void on_newOutputBtn_clicked();
	void on_runBtn_clicked();
	void on_clearBtn_clicked();
    void on_notGateBtn_clicked();
    void on_xnOrGateBtn_clicked();
    void on_xOrGateBtn_clicked();

private:
    Ui::circuitElementsMenu *ui;

    QWidget *levelWidget;
    QLayout *levelLayout;

    bool isGraphCompleted();

    void runEachOutput();
};

#endif // CIRCUITELEMENTSMENU_H
