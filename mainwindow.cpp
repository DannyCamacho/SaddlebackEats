#include "mainwindow.h"
#include "ui_mainwindow.h"

/* ==== MainWindow::Constructor =====================================
    Constructor used to initialize SQLQueryModels restModel and
    menuModel, set the fileName used to populate the SQL database,
    and set the restModel state to ordered by alphabetical order.
================================================================== */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    fileName = "../SaddlebackEats/fastfood.txt";
    // database.populate(fileName); // comment out when using persistent database.
    on_checkBox_stateChanged(0);
}

/* ==== MainWindow::Destructor ======================================
    Destructor used to delete SQLQueryModels restModel and
    menuModel and the MainWindow UI.
================================================================== */
MainWindow::~MainWindow() {
    delete ui;
    delete restModel;
    delete menuModel;
}

/* ==== MainWindow::receiveMessage ==================================
    Message received from successful admin login, launches
    administrative menu. msg is not used for the method since
    message is only received on succesful login. Hides and deletes
    MainWindow UI and creates and shows a new DebugMenu UI.
================================================================== */
void MainWindow::receiveMessage(const QString &msg) {
    hide();
    delete ui;
    debugMenu = new DebugMenu(this);
    debugMenu->show();
}

/* ==== MainWindow::restTableViewUpdate =============================
    Update restaurant tableview and cart quanity, arg1 determines
    whether the restaurants are ordered by distance from saddleback
    or in alphabetical order by restaurant name. The cart quantity
    displayed is also updated.
================================================================== */
void MainWindow::restTableViewUpdate(int arg1) {
    QString sort = arg1 ? "d0" : "restName";
    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY " + sort);
    ui->rest_tableView->setModel(restModel);

    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->cartQuantity->setText(query.value(0).toString());
    if (ui->cartQuantity->text() == "") ui->cartQuantity->setText("0");
}

/* ==== MainWindow::on_checkBox_stateChanged ========================
    Order By Distance Checkbox: Change restaurant order from
    alphabetical order to distance from saddleback. When checkbox
    is unchecked arg1 is equal to 0, when checkbox is check arg1 is
    equal to 1.
================================================================== */
void MainWindow::on_checkBox_stateChanged(int arg1) {
    restTableViewUpdate(arg1);
}

/* ==== MainWindow::on_rest_tableView_clicked =======================
    Loads menu tableview when restaurant is selected from restaurant
    tableview. index is the specific row selected of the tableview.
================================================================== */
void MainWindow::on_rest_tableView_clicked(const QModelIndex &index) {
    menuItem = "";
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, \"$\" || menuPrice as price FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

/* ==== MainWindow::on_actionLogin_triggered ========================
    Login Window: Loads login window when login is selected from
    dropdown.
================================================================== */
void MainWindow::on_actionLogin_triggered() {
    login = new Login(this);
    login->show();
}

/* ==== MainWindow::on_pushButton_4_clicked =========================
    Add Button: Adds selected menu item and quantity to cart database.
    When a menu item is not selected, the method is returned, the
    quantity is determined by the spinBox. If the resulting quantity
    is greater than 100, the method is returned, else the menu item
    with the quantity, price, and restaurant name is added to the cart
    or updated if an entry already existed.
================================================================== */
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

/* ==== MainWindow::on_menu_tableView_clicked =======================
    Updates menuItem and menuPrice when a menu item is selected from
    menu tableview. index is the selected row of the tableview, with
    0 being the name of the item and 1 being the price.
================================================================== */
void MainWindow::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    menuPrice = index.siblingAtColumn(1).data().toString();
}

/* ==== MainWindow::on_cartButton_clicked ===========================
    Shopping Cart: Hides and deletes MainWindow UI and creates and
    shows a new ShoppingCart UI.
================================================================== */
void MainWindow::on_cartButton_clicked() {
    hide();
    delete ui;
    shoppingCart = new ShoppingCart(this);
    shoppingCart->show();
}

/* ==== MainWindow::on_pushButton_clicked ===========================
    Initial List Button: Loads the custom trip with the initial list
    populated (first 10 restaurants). Hides and deletes MainWindow
    UI and creates and shows a new CustomTrip UI.
================================================================== */
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

/* ==== MainWindow::on_pushButton_3_clicked =========================
    Custom Trip Button: Loads the custom trip with no parameters
    loaded. Hides and deletes MainWindow UI and creates and shows a
    new CustomTrip UI.
================================================================== */
void MainWindow::on_pushButton_3_clicked() {
    hide();
    delete ui;
    customTrip = new CustomTrip(this);
    customTrip->show();
}

/* ==== MainWindow::on_actionQuit_triggered =========================
    Quit Option: Closes the program when the Quit option is selected
    in the dropdown.
================================================================== */
void MainWindow::on_actionQuit_triggered() {
     QApplication::quit();
}
