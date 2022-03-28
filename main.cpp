#include "mainwindow.h"
#include <QApplication>

/*! @mainpage Fast Food Fantasy
 *
 *  This Qt program is designed to allow students of saddleback the ability to plan trips to nearby restaurants and purchase food
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
