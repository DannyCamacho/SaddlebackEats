#ifndef DEBUGMENU_H
#define DEBUGMENU_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "database.h"

using namespace std;

namespace Ui { class debugMenu; }
class DebugMenu : public QMainWindow {
    Q_OBJECT

public:
    explicit DebugMenu(QWidget *parent = nullptr);
    ~DebugMenu();

signals:
    void sendMessage(const QString &msg);

private slots:
    void on_rest_tableView_clicked(const QModelIndex &index);
    void on_menu_tableView_clicked(const QModelIndex &index);
    void on_editButton_clicked();
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_importFile_triggered();
    void on_actionLogout_triggered();
    void restTableViewUpdate();
    void menuTableViewUpdate();

private:
    Ui::debugMenu *ui;         /**< debugMenu's ui*/
    QSqlQueryModel* restModel; /**< Holds values for SQL's restaurant*/
    QSqlQueryModel* menuModel; /**< Holds values for SQL's menu*/
    string fileName;           /**< string for the filename*/
    QString restName;          /**< QString for restaurant name*/
    QString menuItem;          /**< QString for menu item name*/
    Database database;         /**< Database for SQL*/
};

#endif // DEBUGMENU_H
