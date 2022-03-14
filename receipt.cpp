#include "mainwindow.h"
#include "receipt.h"
#include "ui_receipt.h"

receipt::receipt(QWidget *parent): ui(new Ui::receipt)
{
    ui->setupUi(this);
    receiptModel = new QSqlQueryModel;
    printReceipt();
}

receipt::~receipt()
{
    delete ui;
    delete receiptModel;
}

void receipt::printReceipt()
{

    receiptModel->setQuery("SELECT restName, menuItem, menuPrice, quantity FROM cart ORDER BY restName");
    ui->receiptTable->setModel(receiptModel);
}
