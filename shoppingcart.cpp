#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "mainwindow.h"

ShoppingCart::ShoppingCart(QWidget *parent): ui(new Ui::ShoppingCart) {
    ui->setupUi(this);
    cartModel = new QSqlQueryModel;
    totModel = new QSqlQueryModel;
    cartTableViewUpdate();
};

ShoppingCart::~ShoppingCart() {
    delete ui;
    delete cartModel;
    delete totModel;
}

void ShoppingCart::cartTableViewUpdate() {
    cartModel->setQuery("SELECT restName, menuItem, menuPrice, quantity FROM cart ORDER BY restName");
    ui->cartTableView->setModel(cartModel);
    totTableViewUpdate();
    calculateTotal();
}

void ShoppingCart::totTableViewUpdate() {
    totModel->setQuery("SELECT restName, '$' || SUM(TRIM(menuPrice, '$') * quantity) FROM cart GROUP BY restName");
    ui->totTableView->setModel(totModel);
}

void ShoppingCart::calculateTotal() {
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT TRIM(menuPrice, '$') * quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->totalAmount->setText(QString::number(query.value(0).toDouble(), 'f', 2));
        if (ui->totalAmount->text() == "") ui->totalAmount->setText("0.00");
}

void ShoppingCart::on_emptyButton_clicked() {
    QSqlQuery query("DROP TABLE cart;");
    menuItem = restName = "";
    ui->totalAmount->setText("0.00");
    query.exec("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");
    cartTableViewUpdate();
}

void ShoppingCart::on_removeButton_clicked() {
    if (menuItem == "" || restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Deletion","Please Select a Menu Item!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query("DELETE FROM cart WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";");
    menuItem = restName = "";
    cartTableViewUpdate();
}

void ShoppingCart::on_updateButton_clicked() {
    if (menuItem == "" || restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Update Quantity","Please Select a Menu Item!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query("UPDATE cart SET quantity =\"" + ui->spinBox->text() + "\" WHERE restName =\"" + restName + "\" AND menuItem = \"" + menuItem + "\";");
    if (ui->spinBox->text().toInt() == 0) on_removeButton_clicked();
    else { menuItem = restName = ""; cartTableViewUpdate(); }
}

void ShoppingCart::on_cartTableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuItem = index.siblingAtColumn(1).data().toString();
}

void ShoppingCart::on_pushButton_6_clicked() {
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
    hide();
    delete ui;
}

void ShoppingCart::on_pushButton_3_clicked() {
    QSqlQuery query("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restNum INTEGER);");
    query.exec("INSERT INTO trip (restNum) SELECT restNum FROM cart;");

    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}
