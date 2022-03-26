#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "customtrip.h"
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
    void totTableViewUpdate();
    void calculateTotal();
    void on_cartTableView_clicked(const QModelIndex &index);
    void on_emptyButton_clicked();
    void on_removeButton_clicked();
    void on_updateButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    QSqlQueryModel* totModel;
    CustomTrip* customTrip;
    QString restName;
    QString menuItem;
    vector<QString> vec;
    vector <double> distAr;

};
#endif // SHOPPINGCART_H
