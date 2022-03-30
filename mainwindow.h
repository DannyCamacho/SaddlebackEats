#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "debugmenu.h"
#include "shoppingcart.h"
#include "customtrip.h"
#include "login.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*! \class MainWindow
 *  \brief Manages all other classes
 *
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    /*! Constructor
     *
     *  Constructor used to initialize SQLQueryModels restModel and menuModel, set the fileName used to populate the SQL database, and set the restModel state to ordered by alphabetical order.
     *  @param QWidget parent
     */
    MainWindow(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  Destructor used to delete SQLQueryModels restModel and menuModel and the MainWindow UI.
     */
    ~MainWindow();

public slots:

    /*! @fn void receiveMessage(const QString &msg)
     *
     *  Message received from successful admin login, launches administrative menu. msg is not used for the method since message is only received on succesful login. Hides and deletes MainWindow UI and creates and shows a new DebugMenu UI.
     *  @param const QString &msg
     */
    void receiveMessage(const QString &msg);

private slots:

    /*! @fn void on_checkBox_stateChanged(int arg1)
     *
     *  Order By Distance Checkbox: Change restaurant order from alphabetical order to distance from saddleback. When checkbox is unchecked arg1 is equal to 0, when checkbox is check arg1 is equal to 1.
     *  @param int arg1
     */
    void on_checkBox_stateChanged(int arg1);

    /*! @fn void on_rest_tableView_clicked(const QModelIndex &index)
     *
     *  Loads menu tableview when restaurant is selected from restaurant tableview. index is the specific row selected of the tableview.
     *  @param const QModelIndex &index
     */
    void on_rest_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_actionLogin_triggered()
     *
     *  Login Window: Loads login window when login is selected from dropdown.
     */
    void on_actionLogin_triggered();

    /*! @fn void on_pushButton_4_clicked()
     *
     *  Add Button: Adds selected menu item and quantity to cart database. When a menu item is not selected, the method is returned, the quantity is determined by the spinBox. If the resulting quantity is greater than 100, the method is returned, else the menu item with the quantity, price, and restaurant name is added to the cart or updated if an entry already existed.
     */
    void on_pushButton_4_clicked();

    /*! @fn void on_menu_tableView_clicked(const QModelIndex &index)
     *
     *  Updates menuItem and menuPrice when a menu item is selected from menu tableview. index is the selected row of the tableview, with 0 being the name of the item and 1 being the price.
     *  @param const QModelIndex &index
     */
    void on_menu_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_cartButton_clicked()
     *
     *  Shopping Cart: Hides and deletes MainWindow UI and creates and shows a new ShoppingCart UI.
     */
    void on_cartButton_clicked();

    /*! @fn void restTableViewUpdate(int arg1)
     *  Update restaurant tableview and cart quanity, arg1 determines whether the restaurants are ordered by distance from saddleback or in alphabetical order by restaurant name. The cart quantity displayed is also updated.
     *  @param int arg1
     */
    void restTableViewUpdate(int arg1);

    /*! @fn void on_pushButton_clicked()
     *  Initial List Button: Loads the custom trip with the initial list populated (first 10 restaurants). Hides and deletes MainWindow UI and creates and shows a new CustomTrip UI.
     *
     */
    void on_pushButton_clicked();

    /*! @fn void on_pushButton_3_clicked()
     *  Custom Trip Button: Loads the custom trip with no parameters loaded. Hides and deletes MainWindow UI and creates and shows a new CustomTrip UI.
     *
     */
    void on_pushButton_3_clicked();

    /*! @fn void on_actionQuit_triggered()
     *
     *  Quit Option: Closes the program when the Quit option is selectedin the dropdown.
     */
    void on_actionQuit_triggered();

private:

    /*! @var Ui::MainWindow *ui
     *  MainWindow's ui
     */
    Ui::MainWindow *ui;

    /*! @var Login* login
     *  Instance of login.h
     */
    Login* login;

    /*! @var DebugMenu* debugMenu
     *  Instance of debugMenu.h
     */
    DebugMenu* debugMenu;

    /*! @var ShoppingCart* shoppingCart
     *  Instance of ShoppingCart.h
     */
    ShoppingCart* shoppingCart;

    /*! @var CustomTrip* customTrip
     *  Instance of customtrip.h
     */
    CustomTrip* customTrip;

    /*! @var Database database
     *  Database for SQL
     */
    Database database;

    /*! @var QSqlQueryModel* restModel
     *  Holds values for SQL's restaurant
     */
    QSqlQueryModel* restModel;

    /*! @var QSqlQueryModel* menuModel
     *  Holds values for SQL's menu
     */
    QSqlQueryModel* menuModel;

    /*! @var QString restName
     *  QString for restaurant name
     */
    QString restName;

    /*! @var QString menuItem
     *  QString for menu item name
     */
    QString menuItem;

    /*! @var QString menuPrice
     *  QString for menu item price
     */
    QString menuPrice;

    /*! @var string fileName
     *  string for the filename
     */
    string fileName;
};
#endif // MAINWINDOW_H
