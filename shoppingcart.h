#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "database.h"

using namespace std;

namespace Ui { class ShoppingCart; }

/*! \class ShoppingCart
 *  \brief Manages the sales of menu items
 *  This class displays the price and distance and allows a user to change the quantity of an menu item or remove it
 */
class ShoppingCart : public QMainWindow {
    Q_OBJECT

public:
    /*! Constructor
     *
     *  Sets up ui. initializes cartModel. sets up shopping cart window
     *  @param QWidget parent
     */
    explicit ShoppingCart(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  deletes ui cartModel
     */
    ~ShoppingCart();

private slots:

    /*! @fn void cartTableViewUpdate()
     *
     *  Updates the table displaying the shopping cart items
     *  @warning Cannot add items from mainwindow while the shopping cart window is displayed
     */
    void cartTableViewUpdate();

    /*! @fn void calculateTotal()
     *
     *  Calculates the total price of the menu items
     */
    void calculateTotal();

    /*! @fn void RecursiveSort(QString restName)
     *
     *  Recursively sorts a list of restaurants based on the shortest distances
     *  @param QString restName
     */
    void RecursiveSort(QString restName);

    /*! @fn void getDistances(QString restName)
     *
     *  Returns array of distances of passed in rest name
     *  @param QString restName
     */
    void getDistances(QString restName);

    /*! @fn on_cartTableView_clicked(const QModelIndex &index)
     *
     *
     *  @param const QModelIndex &index
     */
    void on_cartTableView_clicked(const QModelIndex &index);

    /*! @fn void on_emptyButton_clicked()
     *
     *   Empties the shopping cart
     */
    void on_emptyButton_clicked();

    /*! @fn void on_removeButton_clicked()
     *
     *  Removes an item from the shopping cart
     */
    void on_removeButton_clicked();

    /*! @fn void on_updateButton_clicked()
     *
     *  Updates the shopping cart
     */
    void on_updateButton_clicked();

    /*! @fn void on_pushButton_6_clicked()
     *
     *   Return to mainwindow
     */
    void on_pushButton_6_clicked();

private:

    /*! @var Ui::ShoppingCart *ui
     *  ShoppingCart's ui
     */
    Ui::ShoppingCart *ui;

    /*! @var QSqlQueryModel* cartModel
     *  Holds values for SQL's cart
     */
    QSqlQueryModel* cartModel;

    /*! @var QString restName
     *  QString for restaurant name
     */
    QString restName;

    /*! @var QString menuItem
     *  QString for menu item name
     */
    QString menuItem;

    /*! @var vector<QString> vec
     *  Vector for Restaurant Names
     */
    vector<QString> vec;

    /*! @var vector <double> distAr
     *  Vector for distances
     */
    vector <double> distAr;    /**< Vector for distances*/

};
#endif // SHOPPINGCART_H
