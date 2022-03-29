#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QMainWindow>
#include <QMessageBox>
#include <vector>
#include "database.h"

namespace Ui { class CustomTrip; }
class CustomTrip : public QMainWindow {
    Q_OBJECT

public:
    explicit CustomTrip(QWidget *parent = nullptr);
    ~CustomTrip();

private slots:
    void initializeDistances();
    void calculateTrip(int start);
    void tableViewUpdate();
    void updateTrip();
    void on_pushButton_6_clicked();
    void on_tripTableView_clicked(const QModelIndex &index);
    void on_routeTableView_clicked(const QModelIndex &index);
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_restComboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_3_clicked();

private:
    Ui::CustomTrip *ui;
    QSqlQueryModel* tripModel;
    QSqlQueryModel* routeModel;
    std::vector<int> order;
    QString name;
    bool isAvailable[20];
    double d[20][20];
    int start;
};

#endif // CUSTOMTRIP_H
