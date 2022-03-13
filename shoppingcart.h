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

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
};
#endif // SHOPPINGCART_H
