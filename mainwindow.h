#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QListWidget>
#include <QSqlQueryModel>
#include <sstream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void printDistance(bool sortByDist, QListWidget* list);

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_rest_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    void DatabaseImport();
    void restTableViewUpdate(int arg1);
    QSqlQueryModel* restModel;
    QSqlQueryModel* menuModel;
    std::string fileName;
    QIcon restaurantImage = QIcon(":/rec/resources/resturantImage1.png");
};
#endif // MAINWINDOW_H
