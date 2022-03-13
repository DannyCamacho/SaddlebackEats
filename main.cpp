#include "mainwindow.h"
#include "debugmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    debugMenu  d;
    //shoppingCart s;

    w.show();
    d.show();
    //s.show();
    return a.exec();
}
