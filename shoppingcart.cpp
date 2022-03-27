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
    totModel->setQuery("SELECT restName, SUM(menuPrice * quantity) FROM cart GROUP BY restName");
    ui->totTableView->setModel(totModel);
}

void ShoppingCart::calculateTotal() {
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT menuPrice * quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->totalAmount->setText(QString::number(query.value(0).toDouble(), 'g', 7));
        if (ui->totalAmount->text() == "") ui->totalAmount->setText("0.00");
}

void ShoppingCart::on_emptyButton_clicked() {
    QSqlQuery query("DROP TABLE cart;");
    menuItem = restName = "";
    ui->totalAmount->setText("0.00");
    QSqlQuery cart("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");
    cartTableViewUpdate();
}

void ShoppingCart::on_removeButton_clicked()
{
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
    QSqlQuery query1("DROP TABLE trip;");
    QSqlQuery query2("CREATE TABLE trip (restNum INTEGER);");
    query1.exec("SELECT restNum FROM cart GROUP BY restName;");
    while(query1.next()) query2.exec("INSERT INTO trip (restNum) VALUES (\"" + query1.value(0).toString() + "\");");
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}
