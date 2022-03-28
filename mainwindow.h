#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "debugmenu.h"
#include "shoppingcart.h"
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
     *  Sets up ui. initializes restModel menuModel fileName. populates the database
     *  @param QWidget parent
     */
    MainWindow(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  deletes ui restModel menuModel
     */
    ~MainWindow();

public slots:
    /*! @fn void receiveMessage(const QString &msg)
     *
     *  @param const QString &msg
     */
    void receiveMessage(const QString &msg);

private slots:
    /*! @fn void on_checkBox_stateChanged(int arg1)
     *
     *  @param int arg1
     */
    void on_checkBox_stateChanged(int arg1);

    /*! @fn void on_rest_tableView_clicked(const QModelIndex &index)
     *
     *  @param const QModelIndex &index
     */
    void on_rest_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_actionLogin_triggered()
     *
     *  Opens the window for logging in as an admin
     */
    void on_actionLogin_triggered();

    /*! @fn void on_pushButton_4_clicked()
     *
     *  function is used when pushButton_4 is clicked
     */
    void on_pushButton_4_clicked();

    /*! @fn void on_menu_tableView_clicked(const QModelIndex &index)
     *
     *  @param const QModelIndex &index
     */
    void on_menu_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_cartButton_clicked()
     *
     *  Opens the window for the shopping cart
     */
    void on_cartButton_clicked();

    /*! @fn void restTableViewUpdate(int arg1)
     *
     *  @param int arg1
     */
    void restTableViewUpdate(int arg1);

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
