#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include <QTextEdit>
#include "mainwindow.h"
#include<QDebug>

namespace Ui {
class shoppingCart;
}

class shoppingCart : public MainWindow
{
    Q_OBJECT

public:
    // default constructor
    explicit shoppingCart(QWidget *parent = nullptr);

    //destructor
    ~shoppingCart();


private slots:

    void on_buyButton_clicked();

private:
    Ui::shoppingCart *ui;
    void mainClicked(); //This function is used when 'add item' in MainWindow is clicked
    void enlist(QListWidgetItem *newLine, QListWidget *list);
    void resetTrip(); //Receipts are only displayed for each trip only





};

#endif // SHOPPINGCART_H
