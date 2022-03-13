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
}

void MainWindow::on_checkBox_stateChanged(int arg1) {
    restTableViewUpdate(arg1);
}

void MainWindow::on_rest_tableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

void MainWindow::on_actionLogin_triggered() {
    login = new Login(this);
    login->show();
}

void MainWindow::on_pushButton_4_clicked() {
    if (menuItem == "") return;
    QSqlQuery query;
    QString quantity = ui->spinBox->text();
    query.exec("INSERT INTO cart (restName, menuItem, menuPrice, quantity) VALUES (\"" + restName + "\", \"" + menuItem + "\", \"" + menuPrice + "\", \"" + quantity + "\");");
    menuItem = "";
}

void MainWindow::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    menuPrice = index.siblingAtColumn(1).data().toString();
}

void MainWindow::on_cartButton_clicked() {
    shoppingCart = new ShoppingCart(this);
    shoppingCart->show();
}
