#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"
#include <vector>

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

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    void getDistances(QString restName);
    void RecursiveSort(QString restName);
    vector<QString> v;
    vector <double> distAr;
};
#endif // SHOPPINGCART_H
