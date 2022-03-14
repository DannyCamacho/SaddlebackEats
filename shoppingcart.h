#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"

using namespace std;

namespace Ui { class ShoppingCart; }
class ShoppingCart : public QMainWindow {
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();

private slots:
    void cartTableViewUpdate();
    void calculateTotal();
    void RecursiveSort(QString restName);
    void getDistances(QString restName);

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    vector<QString> vec;
    vector <double> distAr;

};
#endif // SHOPPINGCART_H
