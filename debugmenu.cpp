#include "debugmenu.h"
#include "ui_debugmenu.h"

debugMenu::debugMenu(QWidget *parent): ui(new Ui::debugMenu) {
    ui->setupUi(this);
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    fileName = "../SaddlebackEats/CS1D Spring 2022 New Fast Food Project.txt";
    database.import(fileName);
    restTableViewUpdate();
};

debugMenu::~debugMenu()
{
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
}

void debugMenu::on_menu_tableView_clicked(const QModelIndex &index) {
    menuItem = index.siblingAtColumn(0).data().toString();
    ui->lineEditItemName->setText(index.siblingAtColumn(0).data().toString());
    ui->lineEditItemPrice->setText(index.siblingAtColumn(1).data().toString());
}


void debugMenu::on_editButton_clicked()
{

}




void debugMenu::on_addButton_clicked() {
    if (restName == "") {
        QMessageBox messageBox;
        messageBox.critical(0,"Invalid Add","Please Select a Restaurant!");
        messageBox.setFixedSize(500,200);
        return;
    }

   QSqlQuery query;
   query.prepare("SELECT * FROM menu WHERE restName=:restName AND menuItem=:menuItem");
   query.bindValue(":teamName", restName);
   query.bindValue(":menuItem", menuItem);
   if (!query.exec()) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
   if (query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Duplicate Menu Item","Menu Item already exists!");
       messageBox.setFixedSize(500,200);
       return;
    }
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
