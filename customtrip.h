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

private slots:
    void initializeDistances();
    void calculateTrip(int start);
    void tableViewUpdate();
    void updateTrip();

private:
    Ui::CustomTrip *ui;
    bool isAvailable[20];
    double d[20][20];
    int start;
    std::vector<int> order;
    QSqlQueryModel* tripModel;
    QSqlQueryModel* routeModel;
};

#endif // CUSTOMTRIP_H
