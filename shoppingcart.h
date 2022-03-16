#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"
#include <queue>

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

    void on_cartTableView_clicked(const QModelIndex &index);

    void on_emptyButton_clicked();

    void on_removeButton_clicked();

    void on_updateButton_clicked();

    void on_checkoutButton_clicked();
private:
    Ui::ShoppingCart *ui;
    QSqlQueryModel* cartModel;
    QString restName;
    QString menuItem;
    vector<QString> vec;
    vector <double> distAr;
    float totalDist;
    queue <QString> customAr;
    bool customTrip;

};
#endif // SHOPPINGCART_H
