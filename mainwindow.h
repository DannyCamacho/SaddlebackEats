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
 *  DESCRIPTION GOES HERE
 */
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void receiveMessage(const QString &msg);

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_rest_tableView_clicked(const QModelIndex &index);
    void on_actionLogin_triggered();
    void on_pushButton_4_clicked();
    void on_menu_tableView_clicked(const QModelIndex &index);
    void on_cartButton_clicked();
    void restTableViewUpdate(int arg1);

private:
    Ui::MainWindow *ui;         /**< MainWindow's ui*/
    Login* login;               /**< Instance of Login.h*/
    DebugMenu* debugMenu;       /**< Instance of debugMenu.h*/
    ShoppingCart* shoppingCart; /**< Instance of ShoppingCart.h*/
    Database database;          /**< Database for SQL*/
    QSqlQueryModel* restModel;  /**< Holds values for SQL's restaurant*/
    QSqlQueryModel* menuModel;  /**< Holds values for SQL's menu*/
    QString restName;           /**< QString for restaurant name*/
    QString menuItem;           /**< QString for menu item name*/
    QString menuPrice;          /**< QString for menu item price*/
    string fileName;            /**< string for the filename*/
};
#endif // MAINWINDOW_H
