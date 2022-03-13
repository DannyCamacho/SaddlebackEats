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

private slots:
    void on_rest_tableView_clicked(const QModelIndex &index);

    void on_menu_tableView_clicked(const QModelIndex &index);

    void on_editButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_importFile_triggered();

private:
    Ui::debugMenu *ui;
    QSqlQueryModel* restModel;
    QSqlQueryModel* menuModel;
    string fileName;
    QString restName;
    QString menuItem;
    Database database;
    void restTableViewUpdate();
    void menuTableViewUpdate();
};

#endif // DEBUGMENU_H
