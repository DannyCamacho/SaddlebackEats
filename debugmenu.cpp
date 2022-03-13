#include "debugmenu.h"
#include "ui_debugmenu.h"

debugMenu::debugMenu(QWidget *parent): ui(new Ui::debugMenu) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    restTableViewUpdate();
};

debugMenu::~debugMenu() {
    delete ui;
}

void debugMenu::restTableViewUpdate() {
    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY restName");
    ui->rest_tableView->setModel(restModel);
}

void debugMenu::menuTableViewUpdate() {
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}

void debugMenu::on_rest_tableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
    ui->lineEditItemName->setText("");
    ui->lineEditItemPrice->setText("");
    menuItem = "";
}

void debugMenu::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    ui->lineEditItemName->setText(index.siblingAtColumn(0).data().toString());
    ui->lineEditItemPrice->setText(index.siblingAtColumn(1).data().toString());
}


void debugMenu::on_editButton_clicked() {
    if (restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Edit","Please Select a Restaurant!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query;
    QString newMenuItem = ui->lineEditItemName->text();
    QString q = "SELECT * FROM menu WHERE menuItem =\"" + newMenuItem + "\" AND restName =\"" + restName + "\";";
    query.exec(q);
    if (query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Duplicate Menu Item","Menu Item already exists!");
       messageBox.setFixedSize(500,200);
       return;
    }

    if (newMenuItem == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Edit","Please Input an Item Name!");
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

    query.exec("UPDATE menu SET menuItem =\"" + newMenuItem + "\", menuPrice =\"" + menuPrice + "\" WHERE restName =\"" + restName + "\" AND menuItem = \"" + menuItem + "\";");
    menuItem = "";
    menuTableViewUpdate();
}

void debugMenu::on_addButton_clicked() {
    if (restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Addition","Please Select a Restaurant!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query;
    menuItem = ui->lineEditItemName->text();
    QString q = "SELECT * FROM menu WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";";
    query.exec(q);
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

void debugMenu::on_removeButton_clicked() {
    if (menuItem == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Deletion","Please Select a Menu Item!");
        messageBox.setFixedSize(500,200);
        return;
    }

    QSqlQuery query;
    QString q = "DELETE FROM menu WHERE menuItem =\"" + menuItem + "\" AND restName =\"" + restName + "\";";
    query.exec(q);
    query.next();
    ui->lineEditItemName->setText("");
    ui->lineEditItemPrice->setText("");
    menuItem = "";
    menuTableViewUpdate();
}

void debugMenu::on_importFile_triggered()
{
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

