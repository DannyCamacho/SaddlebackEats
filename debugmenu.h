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
     *  Constructor used to initialize SQLQueryModels restModel and menuModel and update the restaurant tableview based off current restaurant database.
     *  @param QWidget parent
     */
    explicit DebugMenu(QWidget *parent = nullptr);

    /*! Destructor
     *
     *  Destructor used to delete SQLQueryModels restModel and menuModel and the DebugMenu UI.
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
     *  Loads menu tableview when restaurant is selected from restaurant tableview. index is the specific row selected of the tableview. clears the lineedits and menuItem variable.
     *  @param const QModelIndex &index
     */
    void on_rest_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_menu_tableView_clicked(const QModelIndex &index)
     *  Updates menuItem and menuPrice when a menu item is selected from menu tableview. index is the selected row of the tableview, with 0 being the name of the item and 1 being the price.
     */
    void on_menu_tableView_clicked(const QModelIndex &index);

    /*! @fn void on_editButton_clicked()
     *
     *  Edit button used to update an existing entry. initially check for a restaurant choice, then for a menu item selection. A check for a matching menu item name within the restaurant is performed, and a regex check is used to check for a valid monetary value set for the menu price. The item is then updated in the menu database.
     */
    void on_editButton_clicked();

    /*! @fn void on_addButton_clicked()
     *
     *  Add button used to add a non-existing entry. initially check for a restaurant choice, then for a menu item selection. A check for a matching menu item name within the restaurant is performed, and a regex check is used to check for a valid monetary value set for the menu price.The item is then added to the menu database.
     */
    void on_addButton_clicked();

    /*! @fn void on_removeButton_clicked()
     *
     *  Remove button used to remove an existing entry. initially check for a restaurant choice, then for a menu item selection. A check for a matching menu item name within the restaurant is performed. The item is then removed from the menu database.
     */
    void on_removeButton_clicked();

    /*! @fn void on_importFile_triggered()
     *
     *  A file selection window is displayed to the user, the path and filename used to initialize fileName, if no file is selected or another file selection issue is determined, a warning is displayed to the user and the method is returned. if a valid file is selected, the database method import is executed with the file and the restaurant tableview is updated.
     */
    void on_importFile_triggered();

    /*! @fn void on_actionLogout_triggered()
     *
     *  Logout Option: Hides and deletes DebugMenu UI and creates and shows a new MainWindow UI when the Logout option is selected in the dropdown..
     */
    void on_actionLogout_triggered();

    /*! @fn void restTableViewUpdate()
     *
     *  Update the restaurant tableview based off current restaurant database entries.
     */
    void restTableViewUpdate();

    /*! @fn void menuTableViewUpdate()
     *
     *  Update the restaurant tableview based off current restaurant database entries.
     */
    void menuTableViewUpdate();

    /*! @fn void on_actionQuit_triggered()
     *
     *  Quit Option: Closes the program when the Quit option is selected in the dropdown.
     */
    void on_actionQuit_triggered();

private:
    /*! @var Ui::debugMenu *ui
     *  debugMenu's ui
     */
    Ui::debugMenu *ui;

    /*! @var QSqlQueryModel* restModel
     *  Holds values for SQL's restaurant
     */
    QSqlQueryModel* restModel;

    /*! @var QSqlQueryModel* menuModel
     *  Holds values for SQL's menu
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
