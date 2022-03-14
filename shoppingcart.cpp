#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "mainwindow.h"

ShoppingCart::ShoppingCart(QWidget *parent): ui(new Ui::ShoppingCart) {
    ui->setupUi(this);
    cartModel = new QSqlQueryModel;
    cartTableViewUpdate();
};

ShoppingCart::~ShoppingCart() {
    delete ui;
    delete cartModel;
}

void ShoppingCart::cartTableViewUpdate() {
    cartModel->setQuery("SELECT restName, menuItem, menuPrice, quantity FROM cart ORDER BY restName");
    ui->cartTableView->setModel(cartModel);
    calculateTotal();
}

void ShoppingCart::calculateTotal() {
    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT menuPrice * quantity as TOTAL FROM cart) X;");
    if (query.next()) ui->totalAmount->setText(query.value(0).toString());
}
// returns array of distances of passed in rest name
void ShoppingCart::getDistances(QString restName)
    {
        int key = 0;
        QString q = "SELECT restName, restNum FROM cart;";
        QSqlQuery query;
        query.exec(q);
        while(query.next())
        {
            if(query.value(0).toString() == restName)
            {
                key = query.value(1).toInt();
            }
        }
        int count = 0;
        vector<double> distAr; //array declared as static[5]; //array declared as static
        string strkey = "d" + std::to_string(key);
        QString distIterator = QString::fromStdString(strkey);
        QString d = "SELECT " + distIterator + "FROM cart;";
        query.exec(d);

        while(query.next())
        {
           distAr[count] = query.value(0).toDouble();
        }

    }
// best trip formula
void ShoppingCart::RecursiveSort(QString restName)
  {
  QString q = "SELECT d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10 FROM cart WHERE restName = '" + restName + "';";
  QSqlQuery query;
  int key = 0;
  string strkey;
  query.exec(q);
  for(int i = 0; i< 12; i++)
  {
      if(query.value(i).toFloat() == 0.00)
      {
          key = i;
      }
  }
  int i = 0;
  float temp;
  QString rest;
  QString d;
  getDistances(restName);
  float index = 0.01;
  d = "SELECT * FROM cart";
  query.exec(d);
  while(query.next())
  {
  if(index > distAr[i] && distAr[i] != 0.00)
  {
  temp = distAr[i];
  }
  i++;
  }
  strkey = std::to_string(key);
  string strtemp = std::to_string(temp);
  QString qkey = QString::fromStdString(strkey);
  QString qtemp = QString::fromStdString(strtemp);
  rest = "SELECT restName FROM cart WHERE d" + qkey + " = " + qtemp + ";";
  vec[i] = rest;
  d = "DELETE " + rest + "FROM cart;";
  QString l = "SELECT * FROM cart;";
  query.exec(l);
  if(query.next())
  {
  RecursiveSort (rest);
  }
  }
