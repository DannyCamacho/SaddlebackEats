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
    QString s;
    QSqlQuery query;
    string strspin = std::to_string(spinHolder);
    QString qSpinHolder = QString::fromStdString(strspin);
    s = "INSERT INTO cart (restName, menuItem, menuPrice, menuCounter) FROM menu WHERE restName =\"" + restHolder + "\" VALUES (restName, menuItem, menuPrice, \"" + qSpinHolder + "\");";
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
// returns array of distances of passed in rest name
void shoppingCart::getDistances(QString restName)
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
void shoppingCart::RecursiveSort(QString restName)
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
void enlist(QListWidgetItem *newLine, QListWidget *list)
{
    list->addItem(newLine);
}
