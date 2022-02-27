#include "mainwindow.h"
#include "debugmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    debugMenu  d;

    w.show();
    d.show();

    return a.exec();
}
