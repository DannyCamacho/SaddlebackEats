#ifndef DEBUGMENU_H
#define DEBUGMENU_H

#include <QMainWindow>
#include <QTextEdit>
#include "mainwindow.h"
#include<QDebug>



namespace Ui {
class debugMenu;
}

class debugMenu : public MainWindow
{
    Q_OBJECT

public:
    // default constructor
    explicit debugMenu(QWidget *parent = nullptr);

    //destructor
    ~debugMenu();

private slots:
    void on_removeFromList_clicked();

    void on_resturantList_currentRowChanged(int currentRow);

    void on_addToList_clicked();

    void on_sortByDistToggle_toggled(bool checked);

private:
    Ui::debugMenu *ui;

    int mnSelected = -1;
    QIcon restaurantImage = QIcon(":/rec/resources/resturantImage1.png");
    bool isSorted = false;
};

#endif // DEBUGMENU_H
