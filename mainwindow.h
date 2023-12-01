#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLayout>
#include <QMainWindow>
#include <QMessageBox>
#include "./node_classes/andgate.h"
#include "./node_classes/circuitnode.h"
#include "./node_classes/inputnode.h"
#include "./node_classes/orgate.h"
#include "./node_classes/outputnode.h"
#include <vector>

QT_BEGIN_NAMESPACE

namespace Ui {

using std::vector;

class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    OutputNode *outputNode;

    vector<CircuitNode *> nodes;
    void nodeDeleted(CircuitNode *deletedNode);

private slots:
    void on_runBtn_clicked();

private:
    Ui::MainWindow *ui;

    bool isGraphCompleted();
};
#endif // MAINWINDOW_H
