#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLayout>
#include <QMainWindow>
#include "./node_classes/andgate.h"
#include "./node_classes/circuitnode.h"
#include "./node_classes/inputnode.h"
#include "./node_classes/orgate.h"
#include "./node_classes/outputnode.h"

QT_BEGIN_NAMESPACE
namespace Ui {
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

private slots:
    void on_runBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
