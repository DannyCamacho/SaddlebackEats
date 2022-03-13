#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_rest_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Database database;
    QSqlQueryModel* restModel;
    QSqlQueryModel* menuModel;
    QSqlQueryModel* cartModel;
    string fileName;
    void restTableViewUpdate(int arg1);
};
#endif // MAINWINDOW_H
