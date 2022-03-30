#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "mainwindow.h"

/* ==== ShoppingCart::Constructor ===================================
    Constructor used to initialize SQLQueryModels cartModel and
    totModel, and update the cart tableview.
================================================================== */
ShoppingCart::ShoppingCart(QWidget *parent): ui(new Ui::ShoppingCart) {
    ui->setupUi(this);
    cartModel = new QSqlQueryModel;
    totModel = new QSqlQueryModel;
    cartTableViewUpdate();
};

/* ==== ShoppingCart::Destructor ====================================
    Destructor used to delete SQLQueryModels cartModel and
    totModel and the MainWindow UI.
================================================================== */
ShoppingCart::~ShoppingCart() {
    delete ui;
    delete cartModel;
    delete totModel;
}

/* ==== ShoppingCart::cartTableViewUpdate ===========================
    Updates the cartModel/totModel tableviews and calculate and
    display updated total.
================================================================== */
void ShoppingCart::cartTableViewUpdate() {
    cartModel->setQuery("SELECT restName, menuItem, menuPrice, quantity FROM cart ORDER BY restName");
    ui->cartTableView->setModel(cartModel);
    totTableViewUpdate();
    calculateTotal();
}

/* ==== ShoppingCart::totTableViewUpdate ============================
    Updates the totModel based off the cart totals, displayed per
    restautant totals.
================================================================== */
void ShoppingCart::totTableViewUpdate() {
    totModel->setQuery("SELECT restName, '$' || printf(\"%.2f\", SUM(TRIM(menuPrice, '$') * quantity)) FROM cart GROUP BY restName");
    ui->totTableView->setModel(totModel);
}

/* ==== ShoppingCart::calculateTotal ================================
    Calculates and displays the total cost of all menu items within
    the cart.
================================================================== */
void ShoppingCart::calculateTotal() {
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT TRIM(menuPrice, '$') * quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->totalAmount->setText(QString::number(query.value(0).toDouble(), 'f', 2));
    if (ui->totalAmount->text() == "") ui->totalAmount->setText("0.00");
}

/* ==== ShoppingCart::on_emptyButton_clicked ========================
    Deletes the existing cart database, resets menuItem and restName
    to empty QStrings, then creates a new cart database and updates
    the displayed cart tableview.
================================================================== */
void ShoppingCart::on_emptyButton_clicked() {
    QSqlQuery query("DROP TABLE cart;");
    menuItem = restName = "";
    ui->totalAmount->setText("0.00");
    query.exec("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");
    cartTableViewUpdate();
}

/* ==== ShoppingCart::on_removeButton_clicked =======================
    Deletes a menu item from the cart database, if no menu item is
    selected, then a warning message is displayed to the user. Resets
    menuItem and restName to empty QStrings, then creates a new cart
    database and updates the displayed cart tableview.
================================================================== */
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

/* ==== ShoppingCart::on_updateButton_clicked =======================
    Updates the quantity of the selected menu item based off the
    spinBox. If no menu item is selected, then a warning message is
    displayed to the user. If the spinbox is set to 0, the menu item
    is removed from the cart.
================================================================== */
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

/* ==== ShoppingCart::on_cartTableView_clicked ======================
    Variables restName and menuItem are updated to the selected entry
    of the cart tableview.
================================================================== */
void ShoppingCart::on_cartTableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuItem = index.siblingAtColumn(1).data().toString();
}

/* ==== ShoppingCart::on_pushButton_6_clicked =======================
    Return to Main Menu: Hides and deletes ShoppingCart UI and creates
    and shows a new MainWindow UI.
================================================================== */
void ShoppingCart::on_pushButton_6_clicked() {
    hide();
    delete ui;
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
}

/* ==== ShoppingCart::on_pushButton_3_clicked =======================
    Proceed to Route: Populates the trip database based off the
    current cart entries, hides and deletes ShoppingCart UI and
    creates and shows a new CustomTrip UI.
================================================================== */
void ShoppingCart::on_pushButton_3_clicked() {
    QSqlQuery query("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restNum INTEGER);");
    query.exec("INSERT INTO trip (restNum) SELECT restNum FROM cart;");

    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}
