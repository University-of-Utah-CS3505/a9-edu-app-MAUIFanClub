#include <QApplication>
#include "mainmenu.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainMenu startMenu;
    startMenu.show();
    return a.exec();
}
