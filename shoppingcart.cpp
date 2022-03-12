#include "shoppingcart.h"
#include "ui_shoppingcart.h"

shoppingCart::shoppingCart(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::shoppingCart)
{
    ui->setupUi(this);

    //This connects the add button from MainWindow to the table in this class
    connect(this, &MainWindow::cartLink, this, &shoppingCart::mainClicked);
};


shoppingCart::~shoppingCart()
{
    delete ui;
}


//This inserts data into the 'cart' table and displays it on the table
void shoppingCart::mainClicked()
{
    QString q;
    QSqlQuery query;

    q = "INSERT INTO cart SELECT restName, menuItem, menuPrice FROM menu WHERE restName =\"" + restHolder + "\"";
    if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

    cartModel->setQuery("SELECT * FROM cart");
    ui->restTable->setModel(cartModel);
}

//Makes all the calculations of total revenue per restaurant, grand total cost of all restaurants, total number of menu items per restaurant
void shoppingCart::on_buyButton_clicked()
{
    string receiptForm;
    QString q;
    QSqlQuery query;

    //In future, implement a format more similar to an actual receipt
    q = "SELECT restName, menuItem, menuPrice FROM cart ORDER BY restName;";

    query.exec(q);
    while(query.next())
    {
        //CODE IS COMMENTED OUT DUE TO AN ERROR
//        receiptForm = string(query.value(0).toString().toStdString());
//        QListWidgetItem *newLine = new QListWidgetItem(QString::fromStdString(receiptForm));
//        enlist(newLine, ui->receiptList);

//        receiptForm = string(query.value(1).toString().toStdString() + " $ " + query.value(2).toString().toStdString());
//        newLine = new QListWidgetItem(QString::fromStdString(receiptForm));
//        enlist(newLine, ui->receiptList);

    }


}

void enlist(QListWidgetItem *newLine, QListWidget *list)
{
    list->addItem(newLine);
}
