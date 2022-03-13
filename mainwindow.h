#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "debugmenu.h"
#include "login.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

private:
    Ui::MainWindow *ui;
    Login* login;
    DebugMenu* debugMenu;
    Database database;
    QSqlQueryModel* restModel;
    QSqlQueryModel* menuModel;
    string fileName;
    void restTableViewUpdate(int arg1);
    void adminSetup();
};
#endif // MAINWINDOW_H
