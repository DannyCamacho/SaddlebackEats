#include "customtrip.h"
#include "ui_customtrip.h"
#include "mainwindow.h"
#include "shoppingcart.h"

/* ==== CustomTrip::Constructor =====================================
    Constructor used to initialize SQLQueryModels tripModel and
    routeModel, set the starting location to 0 (Saddleback College),
    initialize the location distances, run the recursive method, and
    update both tablesviews.
================================================================== */
CustomTrip::CustomTrip(QWidget *parent): ui(new Ui::CustomTrip) {
    ui->setupUi(this);
    tripModel = new QSqlQueryModel;
    routeModel = new QSqlQueryModel;
    start = 0;
    initializeDistances();
    updateTrip();
    tableViewUpdate();
};

/* ==== CustomTrip::Destructor ======================================
    Destructor used to delete SQLQueryModels tripModel and
    routeModel and the CustomTrip UI.
================================================================== */
CustomTrip::~CustomTrip() {
    delete ui;
    delete tripModel;
    delete routeModel;
}

/* ==== CustomTrip::initializeDistances =============================
    Method used to initialize the comboBox with all restaurant entries,
    update the 2d distances array used in the recursive function, and
    update the cart quantity amount.
================================================================== */
void CustomTrip::initializeDistances() {
    int i = 1;
    ui->restComboBox->addItem("Saddleback College");
    QSqlQuery query("SELECT * FROM restaurant");
    while (query.next()) {
        ui->restComboBox->addItem(query.value(0).toString());
        for (int k = 0; k < 20; ++ k) d[i][k] = query.value(k + 2).toDouble();
        d[0][i] = d[i][0];
        ++i;
    }
    query.exec("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
    if (ui->cartQuantity->text() == "") ui->cartQuantity->setText("0");
}

/* ==== CustomTrip::initializeDistances =============================
    Method used to update the restaurants included in the custom trip,
    the recursive method (calculateTrip) is then called.
================================================================== */
void CustomTrip::updateTrip() {
    for (int i = 0; i < 20; ++i) isAvailable[i] = false;
    QSqlQuery query("SELECT restNum FROM trip");
    while (query.next()) isAvailable[query.value(0).toInt()] = true;
    isAvailable[0] = false;

    calculateTrip(start);
}

/* ==== CustomTrip::calculateTrip ===================================
    Recursive method used to find the closest location from the
    current location, the base case being when start is set to -1.
================================================================== */
void CustomTrip::calculateTrip(int start) {
    if (start == -1) return;

    order.push_back(start);
    isAvailable[start] = false;
    int idx = -1;
    double dist = 999.9;

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i] && d[start][i] < dist) {
            idx = i;
            dist = d[start][i];
            }
    }

    QSqlQuery query("SELECT restName FROM restaurant WHERE restNum =\"" + QString::number(start) + "\"");
    QString restName = query.next() ? query.value(0).toString() : "Saddleback College";
    dist = dist == 999.9 ? 0.0 : dist;

    query.exec("INSERT INTO route (restName, restNum, routeOrder, distToNext) VALUES (\"" + restName + "\", \"" + QString::number(start) + "\", \"" + QString::number(order.size()) + "\", \"" + QString::number(dist) + "\");");

    calculateTrip(idx);
}

/* ==== CustomTrip::tableViewUpdate =================================
    Method used to update the two tables, updates the location
    selection pool based off restaurants currently found within the
    route. the total distance is determined by summing all distances
    found within the route tableview.
================================================================== */
void CustomTrip::tableViewUpdate() {
    routeModel->setQuery("SELECT restName, distToNext FROM route ORDER BY routeOrder");
    ui->routeTableView->setModel(routeModel);

    tripModel->setQuery("DROP TABLE trip;");
    tripModel->setQuery("CREATE TABLE trip(restName TEXT);");
    tripModel->setQuery("INSERT INTO trip (restName) SELECT restName FROM restaurant;");
    tripModel->setQuery("DELETE FROM trip WHERE EXISTS (SELECT restName FROM route WHERE trip.restName = route.restName);");
    tripModel->setQuery("SELECT restName FROM trip");
    ui->tripTableView->setModel(tripModel);

    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT distToNext as TOTAL FROM route) X;");
    if (query.next()) ui->distLabel->setText(QString::number(query.value(0).toDouble(), 'f', 2));
    if (ui->distLabel->text() == "") ui->distLabel->setText("0.00");
}

/* ==== CustomTrip::on_pushButton_6_clicked =========================
    Return to Main Menu Button: Clears exising route table and hides
    and deletes CustomTrip UI and creates and shows a new MainWindow UI.
================================================================== */
void CustomTrip::on_pushButton_6_clicked() {
    tripModel->setQuery("DROP TABLE route;");
    tripModel->setQuery("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    hide();
    delete ui;
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
}

/* ==== CustomTrip::on_tripTableView_clicked ========================
    Updates the name member when a restaurant is selected. index is
    the specific row selected of the tableview. Clears the route
    tableview selection when a trip tableview item is selected.
================================================================== */
void CustomTrip::on_tripTableView_clicked(const QModelIndex &index){
    ui->routeTableView->clearSelection();
    name = index.siblingAtColumn(0).data().toString();
}

/* ==== CustomTrip::on_routeTableView_clicked =======================
    Updates the name member when a restaurant is selected. index is
    the specific row selected of the tableview. Clears the trip
    tableview selection when a route tableview item is selected.
================================================================== */
void CustomTrip::on_routeTableView_clicked(const QModelIndex &index){
    ui->tripTableView->clearSelection();
    name = index.siblingAtColumn(0).data().toString();
}

/* ==== CustomTrip::on_pushButton_9_clicked =========================
    Add Button: Adds the selected restaurant from the trip tableview
    to the route tableview, if a trip tableview entry is not selected,
    a warning message is displayed to the user. The new efficient trip
    is then calculated and displayed.
================================================================== */
void CustomTrip::on_pushButton_9_clicked() {
    QSqlQuery query("SELECT restName FROM trip WHERE restName =\"" + name + "\";");

    if (!query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Invalid Selection","Please Select a Valid Restaurant!");
       messageBox.setFixedSize(500,200);
       return;
    }

    query.exec("SELECT restNum FROM restaurant WHERE restName =\"" + name + "\";");
    QString restNum = query.next() ? query.value(0).toString() : "0";

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");
    query.exec("INSERT INTO trip (restName, restNum) VALUES (\"" + name + "\", \"" + restNum + "\");");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

/* ==== CustomTrip::on_pushButton_10_clicked ========================
    Remove Button: Removes the selected restaurant from the route
    tableview and adds it to the trip tableview, if a route tableview
    entry is not selected, a warning message is displayed to the user.
    The new efficient trip is then calculated and displayed.
================================================================== */
void CustomTrip::on_pushButton_10_clicked() {
    QSqlQuery query("SELECT restName FROM route WHERE restName =\"" + name + "\";");

    if (!query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Invalid Selection","Please Select a Valid Restaurant!");
       messageBox.setFixedSize(500,200);
       return;
    }

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");
    query.exec("DELETE FROM trip WHERE restName =\"" + name + "\";");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

/* ==== CustomTrip::on_restComboBox_currentTextChanged==============
    ComboBox Item Selected: Updates the starting location based off
    the selected comboBox item selected. The trip is then recalculated
    and displayed to the user.
================================================================== */
void CustomTrip::on_restComboBox_currentTextChanged(const QString &arg1) {
    QSqlQuery query("SELECT restNum FROM restaurant WHERE restName =\"" + arg1 + "\";");
    start = query.next() ? query.value(0).toInt() : 0;

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

/* ==== CustomTrip::on_pushButton_3_clicked =========================
    Domino's Pizza Button: Updates the starting location to Domino's
    and updates the comboBox item to display Domino's Pizza. The new
    efficient trip is then calculated and displayed.
================================================================== */
void CustomTrip::on_pushButton_3_clicked() {
    ui->restComboBox->setCurrentText("Domino's Pizza");
    on_restComboBox_currentTextChanged("Domino's Pizza");
}

/* ==== CustomTrip::on_pushButton_2_clicked =========================
    Place Order Button: Changes button text to Processing... and waits
    for 2 seconds to simulate processing a payment. The shopping cart
    table is then reset and a confirmation popup message is displayed
    to the user. If the cart is currently empty, a warning popup is
    displayed to the user.
================================================================== */
void CustomTrip::on_pushButton_2_clicked() {
    QSqlQuery query("SELECT * FROM cart");
    if (query.next()) {
        ui->pushButton_2->setText("Processing...");
        QTime dieTime= QTime::currentTime().addSecs(2);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

       QMessageBox messageBox;
       messageBox.information(0,"Order Confirmation","Your order has been successfully placed!");
       messageBox.setFixedSize(500,200);

       query.exec("DROP TABLE cart;");
       query.exec("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");

       ui->pushButton_2->setText("Place Order");

       query.exec("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
       if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
       if (ui->cartQuantity->text() == "") ui->cartQuantity->setText("0");

    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Empty Cart","Unable to place order!");
        messageBox.setFixedSize(500,200);
        return;
    }
}

/* ==== CustomTrip::on_cartButton_clicked ===========================
    Shopping Cart Button: Clears exising route table and hides and
    deletes CustomTrip UI and creates and shows a new ShoppingCart UI.
================================================================== */
void CustomTrip::on_cartButton_clicked() {
    tripModel->setQuery("DROP TABLE route;");
    tripModel->setQuery("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    hide();
    delete ui;
    ShoppingCart* shoppingCart = new ShoppingCart(this);
    shoppingCart->show();
}
