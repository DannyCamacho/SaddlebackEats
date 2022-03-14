#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"
#include "receipt.h"

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

    void on_pushButton_3_clicked();

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    receipt *receipt;

};
#endif // SHOPPINGCART_H
