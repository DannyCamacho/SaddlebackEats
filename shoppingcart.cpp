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

void ShoppingCart::on_emptyButton_clicked() {
    QSqlQuery query("DROP TABLE cart;");
    menuItem = restName = "";
    ui->totalAmount->setText("0.00");
    QSqlQuery cart("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");
    cartTableViewUpdate();
}

void ShoppingCart::on_removeButton_clicked()
{
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

void ShoppingCart::on_cartTableView_clicked(const QModelIndex &index) {
    restName = index.siblingAtColumn(0).data().toString();
    menuItem = index.siblingAtColumn(1).data().toString();
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
  QString q = "SELECT d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10 FROM cart WHERE restName = '" + restName + "';";  // get distances for specific restaurant
  QSqlQuery query;
  int key = 0;
  string strkey;
  query.exec(q);
  for(int i = 0; i< 12; i++)
  {
      if(query.value(i).toFloat() == 0.00)
      {
          key = i;                              // key is the number restaurant it is in the table
      }
  }
  int i = 0;
  float temp;
  QString rest;
  QString d;
  getDistances(restName);                       // creates a vector of the distances to all other restaurants from initial restaurant
  float index = 0.01;
  d = "SELECT * FROM cart";
  query.exec(d);
  while(query.next())
  {
  if(index > distAr[i] && distAr[i] != 0.00)       // finds the closest restaurant that is not the same restaurant
  {
  temp = distAr[i];                                 // temp equals the closest restaurant
  }
  i++;
  }
  strkey = std::to_string(key);
  string strtemp = std::to_string(temp);
  QString qkey = QString::fromStdString(strkey);
  QString qtemp = QString::fromStdString(strtemp);
  rest = "SELECT restName FROM cart WHERE d" + qkey + " = " + qtemp + ";";  // finds restaurant key of the closest restaurant
  vec[i] = rest;                                                            // inserts it into vector
  d = "DELETE " + rest + "FROM cart;";                                      // deletes starting restaurant so it cannot repeat
  QString l = "SELECT * FROM cart;";                                        // selects all values from cart to make sure there are still more restaurants left
  query.exec(l);
  if(query.next())
  {
  RecursiveSort (rest);                                                     // if there are more restaurants left to visit, we find the next closest
  }
  }
