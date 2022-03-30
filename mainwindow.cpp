#include "mainwindow.h"
#include "ui_mainwindow.h"

// Constructor for MainWindow.
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    fileName = "../SaddlebackEats/fastfood.txt";
    database.populate(fileName); // comment out when using persistent database.
    on_checkBox_stateChanged(0);
}

// Destructor for MainWindow.
MainWindow::~MainWindow() {
    delete ui;
    delete restModel;
    delete menuModel;
}

// Message received from successful admin login, launches administrative menu.
void MainWindow::receiveMessage(const QString &msg) {
    hide();
    delete ui;
    debugMenu = new DebugMenu(this);
    debugMenu->show();
}

// Update restaurant tableview and cart quanity.
void MainWindow::restTableViewUpdate(int arg1) {
    QString sort = arg1 ? "d0" : "restName";
    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY " + sort);
    ui->rest_tableView->setModel(restModel);
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
    if (ui->cartQuantity->text() == "") ui->cartQuantity->setText("0");
}

// Order By Distance Checkbox: Change restaurant order from alphabetical order to distance from saddleback.
void MainWindow::on_checkBox_stateChanged(int arg1) {
    restTableViewUpdate(arg1);
}

// Loads menu tableview when restaurant is selected from restaurant tableview.
void MainWindow::on_rest_tableView_clicked(const QModelIndex &index) {
    menuItem = "";
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, \"$\" || menuPrice as price FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

// Login Window: Loads login window when login is selected from dropdown.
void MainWindow::on_actionLogin_triggered() {
    login = new Login(this);
    login->show();
}

// Add Button: Adds selected menu item and quantity to cart database.
void MainWindow::on_pushButton_4_clicked() {
    if (menuItem == "") return;

    int quantity = ui->spinBox->text().toInt();
    QString restNum = "";

    QSqlQuery query("SELECT restNum FROM restaurant where restName =\"" + restName + "\";");
    if (query.next()) restNum = query.value(0).toString();

    QString q = "INSERT INTO cart (restName, restNum, menuItem, menuPrice, quantity) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + menuItem + "\", \"" + menuPrice + "\", \"" + QString::number(quantity) + "\");";
    query.exec("SELECT quantity FROM cart where restName =\"" + restName + "\" AND menuItem =\"" + menuItem + "\";");
    if (query.next()) {
        quantity += query.value(0).toInt();
        if (quantity > 100) return;
        q = "UPDATE cart SET restName =\"" + restName + "\", menuItem =\"" + menuItem + "\", menuPrice =\"" + menuPrice + "\", quantity =\"" + QString::number(quantity) + "\" WHERE restName =\"" + restName + "\" AND menuItem =\"" + menuItem + "\";";
    }
    query.exec(q);
    query.exec("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
}

// Updates menuItem and menuPrice when a menu item is selected from menu tableview
void MainWindow::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    menuPrice = index.siblingAtColumn(1).data().toString();
}

// Shopping Cart: Opens shopping cart window and closes main window.
void MainWindow::on_cartButton_clicked() {
    shoppingCart = new ShoppingCart(this);
    shoppingCart->show();
    hide();
    delete ui;
}

// Initial List Button: Loads the custom trip with the initial list populated.
void MainWindow::on_pushButton_clicked() {
    QSqlQuery query1("DROP TABLE trip;");
    QSqlQuery query2("CREATE TABLE trip (restNum INTEGER);");
    query1.exec("SELECT restNum FROM restaurant ORDER BY restNum LIMIT 10;");
    while(query1.next()) query2.exec("INSERT INTO trip (restNum) VALUES (\"" + query1.value(0).toString() + "\");");
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}

// Custom Trip Button: Loads the custom trip with no parameters loaded.
void MainWindow::on_pushButton_3_clicked() {
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}

// Quit Option: Closes the program when the Quit option is selected in the dropdown.
void MainWindow::on_actionQuit_triggered() {
     QApplication::quit();
}
