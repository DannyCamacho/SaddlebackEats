#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "customtrip.h"
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
     *  Constructor used to initialize SQLQueryModels cartModel and totModel, and update the cart tableview.
     *  @param QWidget parent
     */
    explicit ShoppingCart(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  Destructor used to delete SQLQueryModels cartModel and totModel and the MainWindow UI.
     */
    ~ShoppingCart();

private slots:

    /*! @fn void cartTableViewUpdate()
     *
     *  Updates the cartModel/totModel tableviews and calculate and display updated total.
     */
    void cartTableViewUpdate();

    /*! @fn void totTableViewUpdate()
     *
     *  Updates the totModel based off the cart totals, displayed per restautant totals.
     */
    void totTableViewUpdate();

    /*! @fn void calculateTotal()
     *
     *  Calculates and displays the total cost of all menu items within the cart.
     */
    void calculateTotal();

    /*! @fn on_cartTableView_clicked(const QModelIndex &index)
     *
     *  Variables restName and menuItem are updated to the selected entry of the cart tableview.
     *  @param const QModelIndex &index
     */
    void on_cartTableView_clicked(const QModelIndex &index);

    /*! @fn void on_emptyButton_clicked()
     *
     *   Deletes the existing cart database, resets menuItem and restNameto empty QStrings, then creates a new cart database and updates the displayed cart tableview.
     */
    void on_emptyButton_clicked();

    /*! @fn void on_removeButton_clicked()
     *
     *  Deletes a menu item from the cart database, if no menu item is selected, then a warning message is displayed to the user. Resets menuItem and restName to empty QStrings, then creates a new cart database and updates the displayed cart tableview.
     */
    void on_removeButton_clicked();

    /*! @fn void on_updateButton_clicked()
     *
     *  Updates the quantity of the selected menu item based off the spinBox. If no menu item is selected, then a warning message is displayed to the user. If the spinbox is set to 0, the menu item is removed from the cart.
     */
    void on_updateButton_clicked();

    /*! @fn void on_pushButton_6_clicked()
     *
     *   Return to Main Menu: Hides and deletes ShoppingCart UI and creates and shows a new MainWindow UI.
     */
    void on_pushButton_6_clicked();

    /*! @fn void on_pushButton_3_clicked()
     *
     *   Proceed to Route: Populates the trip database based off the current cart entries, hides and deletes ShoppingCart UI and creates and shows a new CustomTrip UI.
     */
    void on_pushButton_3_clicked();

private:
    /*! @var Ui::ShoppingCart *ui
     *  ShoppingCart's ui
     */
    Ui::ShoppingCart *ui;

    /*! @var QSqlQueryModel* cartModel
     *  Holds values for SQL's cart
     */
    QSqlQueryModel* cartModel;

    /*! @var QSqlQueryModel* totModel
     *  Holds values for SQL's total values
     */
    QSqlQueryModel* totModel;

    /*! @var CustomTrip* customTrip
     *  Instance of customtrip.h
     */
    CustomTrip* customTrip;

    /*! @var QString restName
     *  QString for restaurant name
     */
    QString restName;

    /*! @var QString menuItem
     *  QString for menu item name
     */
    QString menuItem;
};
#endif // SHOPPINGCART_H
