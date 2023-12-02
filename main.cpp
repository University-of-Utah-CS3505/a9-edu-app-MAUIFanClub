#include "mainwindow.h"
#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainMenu startMenu;
    startMenu.show();
    return a.exec();
}
