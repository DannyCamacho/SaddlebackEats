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

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    void cartTableViewUpdate();
};
#endif // SHOPPINGCART_H
