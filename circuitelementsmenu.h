#ifndef CIRCUITELEMENTSMENU_H
#define CIRCUITELEMENTSMENU_H

#include <QLayout>
#include <QMessageBox>
#include <QWidget>
#include "dragablewidget.h"
#include "node_classes/andgate.h"
#include "node_classes/inputnode.h"
#include "node_classes/nandgate.h"
#include "node_classes/norgate.h"
#include "node_classes/orgate.h"
#include "node_classes/outputnode.h"
#include <vector>

namespace Ui {
class circuitElementsMenu;
}

class circuitElementsMenu : public DragableWidget
{
    Q_OBJECT

public:
    explicit circuitElementsMenu(QWidget *parent = nullptr);
    ~circuitElementsMenu();

    vector<CircuitNode *> nodes;
    vector<CircuitNode *> outputNodes;
    void nodeDeleted(CircuitNode *deletedNode);

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

private:
    Ui::circuitElementsMenu *ui;
    std::vector <QWidget*> x;
    QWidget *levelWidget;
    QLayout *levelLayout;

    bool isGraphCompleted();

    void runEachOutput();
};

#endif // CIRCUITELEMENTSMENU_H
