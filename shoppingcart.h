#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"

using namespace std;

namespace Ui { class ShoppingCart; }

/*! \class ShoppingCart
 *  \brief Manages the sales of menu items
 *  DESCRIPTION GOES HERE
 */
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

    void on_pushButton_6_clicked();

private:
    Ui::ShoppingCart *ui;      /**< ShoppingCart's ui*/
    QSqlQueryModel* cartModel; /**< Holds values for SQL's cart*/
    QString restName;          /**< QString for restaurant name*/
    QString menuItem;          /**< QString for menu item name*/
    vector<QString> vec;       /**< Vector for Restaurant Names*/
    vector <double> distAr;    /**< Vector for distances*/

};
#endif // SHOPPINGCART_H
