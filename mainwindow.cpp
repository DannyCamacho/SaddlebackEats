#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    fileName = "../SaddlebackEats/fastfood.txt";
    database.populate(fileName);
    on_checkBox_stateChanged(0);
}

MainWindow::~MainWindow() {
    delete ui;
    delete restModel;
    delete menuModel;
}

void MainWindow::receiveMessage(const QString &msg) {
    hide();
    delete ui;
    debugMenu = new DebugMenu(this);
    debugMenu->show();
}

void MainWindow::restTableViewUpdate(int arg1) {
    QString sort = arg1 ? "d0" : "restName";
    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY " + sort);
    ui->rest_tableView->setModel(restModel);
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
    if (ui->cartQuantity->text() == "") ui->cartQuantity->setText("0");
}

void MainWindow::on_checkBox_stateChanged(int arg1) {
    restTableViewUpdate(arg1);
}

void MainWindow::on_rest_tableView_clicked(const QModelIndex &index) {
    menuItem = "";
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, \"$\" || menuPrice as price FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

void MainWindow::on_actionLogin_triggered() {
    login = new Login(this);
    login->show();
}

void MainWindow::on_pushButton_4_clicked() {
    if (menuItem == "" || ui->spinBox->text().toInt() == 0) {
        QMessageBox messageBox;
        messageBox.critical(0,"Missing Menu Item", "Menu item must be selected");
        messageBox.setFixedSize(500,200);
        return;
    }
    int quantity = ui->spinBox->text().toInt();
    QString restNum = "";

    QSqlQuery query("SELECT restNum FROM restaurant where restName =\"" + restName + "\";");
    if (query.next()) restNum = query.value(0).toString();

    QString q = "INSERT INTO cart (restName, restNum, menuItem, menuPrice, quantity) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + menuItem + "\", \"" + menuPrice + "\", \"" + QString::number(quantity) + "\");";
    query.exec("SELECT quantity FROM cart where restName =\"" + restName + "\" AND menuItem =\"" + menuItem + "\";");
    if (query.next()) {
        quantity += query.value(0).toInt();
        if (quantity > 100) {
            QMessageBox messageBox;
            messageBox.critical(0,"Quantity Limit", "Menu item quantity cannot exceed 100");
            messageBox.setFixedSize(500,200);
            return;
        }
        q = "UPDATE cart SET restName =\"" + restName + "\", menuItem =\"" + menuItem + "\", menuPrice =\"" + menuPrice + "\", quantity =\"" + QString::number(quantity) + "\" WHERE restName =\"" + restName + "\" AND menuItem =\"" + menuItem + "\";";
    }
    query.exec(q);
    query.exec("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
}

void MainWindow::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    menuPrice = index.siblingAtColumn(1).data().toString();
}

void MainWindow::on_cartButton_clicked() {
    shoppingCart = new ShoppingCart(this);
    shoppingCart->show();
    hide();
    delete ui;
}

void MainWindow::on_pushButton_clicked() { // initial list trip
    QSqlQuery query1("DROP TABLE trip;");
    QSqlQuery query2("CREATE TABLE trip (restNum INTEGER);");
    query1.exec("SELECT restNum FROM restaurant ORDER BY restNum LIMIT 10;");
    while(query1.next()) query2.exec("INSERT INTO trip (restNum) VALUES (\"" + query1.value(0).toString() + "\");");
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}

void MainWindow::on_pushButton_3_clicked() { // custom trip
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}
