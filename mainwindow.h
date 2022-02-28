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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Brandon Display function
    void printDistance(bool sortByDist, QListWidget* list)
    {
        ostringstream fullList;
        QSqlQuery query;
        QString q;
        string s;
        string restName;
        string listLine;

//        this->ui->restaurantLabel->setText("Saddleback Distances");

        if(sortByDist)
            q = "SELECT restName, d0 FROM restaurant ORDER BY d0;";
        else
            q = "SELECT restName, d0 FROM restaurant ORDER BY restName;";

        query.exec(q);
        while(query.next())
        {

//            fullList << query.value(0).toString().toStdString() << " - " << query.value(1).toString().toStdString() << " Miles" << endl;
            listLine = string(query.value(0).toString().toStdString() + " - " + query.value(1).toString().toStdString() + " Miles");
            QListWidgetItem* newItem = new QListWidgetItem(resturantImage, QString::fromStdString(listLine));
            list->addItem(newItem);

        }

//        this->ui->dListLabel->setText(QString::fromUtf8(fullList.str()));
    }


private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_rest_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void DatabaseConnect();
    void DatabaseInit();
    void DatabasePopulate();
    void restTableViewUpdate(int arg1);
    QSqlQueryModel* restModel;
    QSqlQueryModel* menuModel;
    std::string fileName;
    QIcon resturantImage = QIcon(":/rec/resources/resturantImage1.png");
};
#endif // MAINWINDOW_H
