#ifndef NODEQUICKCREATEMENU_H
#define NODEQUICKCREATEMENU_H

#include <QPoint>
#include <QWidget>
#include "circuitmanager.h"

namespace Ui {
class NodeQuickCreateMenu;
}

class NodeQuickCreateMenu : public QWidget
{
    Q_OBJECT

public:
    explicit NodeQuickCreateMenu(CircuitManager *circuitManager, QWidget *parent = nullptr);
    ~NodeQuickCreateMenu();

    CircuitNode *currentNode;

    QPushButton *inputBtn;
    QPushButton *outputBtn;

private slots:
    void on_andBtn_clicked();
    void on_nAndBtn_clicked();
    void on_orBtn_clicked();
    void on_nOrBtn_clicked();
    void on_xOrBtn_clicked();
    void on_xnOrBtn_clicked();
    void on_qtNotBtn_clicked();
    void on_qcOutputBtn_clicked();
    void on_qcInputBtn_clicked();

    void mouseMoveEvent(QMouseEvent *event) override;
    virtual void leaveEvent(QEvent *event);

private:
    Ui::NodeQuickCreateMenu *ui;
    CircuitManager *circuitManager;
    void updateNewNode();
};

#endif // NODEQUICKCREATEMENU_H
