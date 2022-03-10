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

    void addCart();

private slots:


private:
    Ui::shoppingCart *ui;




};

#endif // SHOPPINGCART_H
