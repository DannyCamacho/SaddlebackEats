#include "debugmenu.h"
#include "ui_debugmenu.h"
#include "mainwindow.h"

/* ==== DebugMenu::Constructor ======================================
    Constructor used to initialize SQLQueryModels restModel and
    menuModel and update the restaurant tableview based off current
    restaurant database.
================================================================== */
DebugMenu::DebugMenu(QWidget *parent): ui(new Ui::debugMenu) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    restTableViewUpdate();
};

/* ==== DebugMenu::Destructor ======================================
    Destructor used to delete SQLQueryModels restModel and
    menuModel and the DebugMenu UI.
================================================================== */
DebugMenu::~DebugMenu() {
    delete ui;
    delete restModel;
    delete menuModel;
}

/* ==== DebugMenu::restTableViewUpdate ==============================
    Update the restaurant tableview based off current restaurant
    database entries.
================================================================== */
void DebugMenu::restTableViewUpdate() {
    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY restName");
    ui->rest_tableView->setModel(restModel);
}

/* ==== DebugMenu::menuTableViewUpdate ==============================
    Update the menu tableview based off current menu database entries
    by the selected restaurant tableview entry.
================================================================== */
void DebugMenu::menuTableViewUpdate() {
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

/* ==== DebugMenu::on_rest_tableView_clicked ========================
    Loads menu tableview when restaurant is selected from restaurant
    tableview. index is the specific row selected of the tableview.
    clears the lineedits and menuItem variable.
================================================================== */
void DebugMenu::on_rest_tableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
    ui->lineEditItemName->setText("");
    ui->lineEditItemPrice->setText("");
    menuItem = "";
}

/* ==== DebugMenu::on_menu_tableView_clicked ========================
    Updates menuItem and menuPrice when a menu item is selected from
    menu tableview. index is the selected row of the tableview, with
    0 being the name of the item and 1 being the price.
================================================================== */
void DebugMenu::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    ui->lineEditItemName->setText(index.siblingAtColumn(0).data().toString());
    ui->lineEditItemPrice->setText(index.siblingAtColumn(1).data().toString());
}

/* ==== DebugMenu::on_editButton_clicked ============================
    Edit button used to update an existing entry. initially check for
    a restaurant choice, then for a menu item selection. A check for
    a matching menu item name within the restaurant is performed, and
    a regex check is used to check for a valid monetary value set for
    the menu price. The item is then updated in the menu database.
================================================================== */
void DebugMenu::on_editButton_clicked() {
    if (restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Edit","Please Select a Restaurant!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QString newMenuItem = ui->lineEditItemName->text();
    QString menuPrice = ui->lineEditItemPrice->text();

    if (newMenuItem == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Edit","Please Input an Item Name!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query("UPDATE menu SET menuItem =\"TEMPORARYITEMNAME\", menuPrice =\"" + menuPrice + "\" WHERE restName =\"" + restName + "\" AND menuItem = \"" + menuItem + "\";");
    query.exec("SELECT * FROM menu WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";");

    if (query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Duplicate Menu Item","Menu Item already exists!");
       messageBox.setFixedSize(500,200);
       query.exec("UPDATE menu SET menuItem =\"" + menuItem + "\", menuPrice =\"" + menuPrice + "\" WHERE restName =\"" + restName + "\" AND menuItem = \"TEMPORARYITEMNAME\";");
       return;
    }

    QRegularExpression re("^([0-9]{1,3},([0-9]{3},)*[0-9]{3}|[0-9]+)(.[0-9][0-9])?$");
    QRegularExpressionMatch match = re.match(menuPrice);

    if (!match.hasMatch()) {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Price","Please Input a Valid Price!");
        messageBox.setFixedSize(500,200);
        return;
    }

    query.exec("UPDATE menu SET menuItem =\"" + newMenuItem + "\", menuPrice =\"" + menuPrice + "\" WHERE restName =\"" + restName + "\" AND menuItem = \"TEMPORARYITEMNAME\";");
    menuItem = "";
    menuTableViewUpdate();
}

/* ==== DebugMenu::on_addButton_clicked =============================
    Add button used to add a non-existing entry. initially check for
    a restaurant choice, then for a menu item selection. A check for
    a matching menu item name within the restaurant is performed, and
    a regex check is used to check for a valid monetary value set for
    the menu price.The item is then added to the menu database.
================================================================== */
void DebugMenu::on_addButton_clicked() {
    if (restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Addition","Please Select a Restaurant!");
        messageBox.setFixedSize(500,200);
        return;
    }

    menuItem = ui->lineEditItemName->text();
    QSqlQuery query("SELECT * FROM menu WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";");

    if (query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Duplicate Menu Item","Menu Item already exists!");
       messageBox.setFixedSize(500,200);
       return;
    }

    if (menuItem == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Addition","Please Input an Item Name!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QString menuPrice = ui->lineEditItemPrice->text();
    QRegularExpression re("^([0-9]{1,3},([0-9]{3},)*[0-9]{3}|[0-9]+)(.[0-9][0-9])?$");
    QRegularExpressionMatch match = re.match(menuPrice);
    if (!match.hasMatch()) {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Price","Please Input a Valid Price!");
        messageBox.setFixedSize(500,200);
        return;
    }

    query.exec("INSERT INTO menu (restName, menuItem, menuPrice) VALUES (\"" + restName + "\", \"" + menuItem + "\", \"" + menuPrice + "\");");
    menuItem = "";
    menuTableViewUpdate();
}

/* ==== DebugMenu::on_removeButton_clicked ==========================
    Remove button used to remove an existing entry. initially check for
    a restaurant choice, then for a menu item selection. A check for
    a matching menu item name within the restaurant is performed. The
    item is then removed from the menu database.
================================================================== */
void DebugMenu::on_removeButton_clicked() {
    if (menuItem == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Deletion","Please Select a Menu Item!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query("DELETE FROM menu WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";");
    ui->lineEditItemName->setText("");
    ui->lineEditItemPrice->setText("");
    menuItem = "";
    menuTableViewUpdate();
}

/* ==== DebugMenu::on_importFile_triggered ==========================
    A file selection window is displayed to the user, the path and
    filename used to initialize fileName, if no file is selected or
    another file selection issue is determined, a warning is displayed
    to the user and the method is returned. if a valid file is selected,
    the database method import is executed with the file and the
    restaurant tableview is updated.
================================================================== */
void DebugMenu::on_importFile_triggered() {
    QString filename = QFileDialog::getOpenFileName(this, "Select Import File");
    fileName = filename.toStdString();
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot import file: " + file.errorString());
        return;
    }

    database.import(fileName);
    restTableViewUpdate();
}

/* ==== DebugMenu::on_actionLogout_triggered ========================
    Logout Option: Hides and deletes DebugMenu UI and creates and
    shows a new MainWindow UI when the Logout option is selected in
    the dropdown..
================================================================== */
void DebugMenu::on_actionLogout_triggered() {
    hide();
    delete ui;
    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
}

/* ==== DebugMenu::on_actionQuit_triggered =========================
    Quit Option: Closes the program when the Quit option is selected
    in the dropdown.
================================================================== */
void DebugMenu::on_actionQuit_triggered() {
     QApplication::quit();
}
