#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "mainwindow.h"

ShoppingCart::ShoppingCart(QWidget *parent): ui(new Ui::ShoppingCart) {
    ui->setupUi(this);
    cartModel = new QSqlQueryModel;
    cartTableViewUpdate();
};

ShoppingCart::~ShoppingCart() {
    delete ui;
}

void ShoppingCart::cartTableViewUpdate() {
    cartModel->setQuery("SELECT restName, menuItem, menuPrice, quantity FROM cart ORDER BY restName");
    ui->cartTableView->setModel(cartModel);
    calculateTotal();
}

void ShoppingCart::calculateTotal() {
    QString total;
    QSqlQuery query;
    query.exec("SELECT SUM(X.TOTAL) FROM (SELECT menuPrice * quantity as TOTAL FROM cart) X;");
    if (query.next()) total = query.value(0).toString();
    ui->totalAmount->setText(total);
}
