#ifndef DEBUGMENU_H
#define DEBUGMENU_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "database.h"

using namespace std;

namespace Ui { class debugMenu; }

/*! \class DebugMenu
 *  \brief Allows the restaurant list to be edited
 *  This class can add restaurants from an inputfile and edit the name and price of a menu item
 *
 */
class DebugMenu : public QMainWindow {
    Q_OBJECT

public:

    /*! Constructor
     *
     *  Sets up ui. initializes restModel menuModel
     *  @param QWidget parent
     */
    explicit DebugMenu(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  deletes ui restModel menuModel
     */
    ~DebugMenu();

signals:
    /*! @fn void sendMessage(const QString &msg)
     *
     *  @param const QString &msg
     */
    void sendMessage(const QString &msg);

private slots:

    /*! @fn void on_rest_tableView_clicked(const QModelIndex &index)
     *
     *  @param const QModelIndex &index
     */
    void on_rest_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_menu_tableView_clicked(const QModelIndex &index)
     *
     *  @param const QModelIndex &index
     */
    void on_menu_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_editButton_clicked()
     *
     *  Saves changes made to the restaurant list
     */
    void on_editButton_clicked();

    /*! @fn void on_addButton_clicked()
     *
     *  Adds restaurant(s) from an input file
     */
    void on_addButton_clicked();

    /*! @fn void on_removeButton_clicked()
     *
     *  Removes a restaurant
     */
    void on_removeButton_clicked();

    /*! @fn void on_importFile_triggered()
     *
     *  imports the input file
     */
    void on_importFile_triggered();

    /*! @fn void on_actionLogout_triggered()
     *
     *  Returns to the mainwindow
     */
    void on_actionLogout_triggered();

    /*! @fn void restTableViewUpdate()
     *
     *  Updates the tableview for restaurants
     */
    void restTableViewUpdate();

    /*! @fn void menuTableViewUpdate()
     *
     *  Updates the tableview for the menu
     */
    void menuTableViewUpdate();

private:

    /*! @var Ui::debugMenu *ui
     *  debugMenu's ui
     */
    Ui::debugMenu *ui;

    /*! @var QSqlQueryModel* menuModel
     *  Holds values for SQL's menu
     */
    QSqlQueryModel* restModel;

    /*! @var QSqlQueryModel* restModel
     *  Holds values for SQL's restaurant
     */
    QSqlQueryModel* menuModel;

    /*! @var string fileName
     *  string for the filename
     */
    string fileName;

    /*! @var QString restName
     *  QString for restaurant name
     */
    QString restName;

    /*! @var QString menuItem
     *  QString for menu item name
     */
    QString menuItem;

    /*! @var Database database
     *  Database for SQL
     */
    Database database;
};

#endif // DEBUGMENU_H
