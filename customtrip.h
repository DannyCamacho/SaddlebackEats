#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QMainWindow>
#include <vector>
#include "database.h"

namespace Ui { class CustomTrip; }
class CustomTrip : public QMainWindow {
    Q_OBJECT

public:
    explicit CustomTrip(QWidget *parent = nullptr);
    ~CustomTrip();
    void calculateTrip(int start);


private slots:
    void initalList();
    void routeTableViewUpdate();

private:
    Ui::CustomTrip *ui;
    bool isAvailable[20];
    double d[20][20];
    std::vector<int> order;
    QSqlQueryModel* tripModel;
    QSqlQueryModel* routeModel;
};

#endif // CUSTOMTRIP_H
