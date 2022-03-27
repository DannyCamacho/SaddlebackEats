#include "customtrip.h"
#include "ui_customtrip.h"
#include "mainwindow.h"

CustomTrip::CustomTrip(QWidget *parent): ui(new Ui::CustomTrip) {
    ui->setupUi(this);
    tripModel = new QSqlQueryModel;
    routeModel = new QSqlQueryModel;
    start = 0;
    initializeDistances();
    updateTrip();
    tableViewUpdate();
};

CustomTrip::~CustomTrip() {
    delete ui;
    delete tripModel;
    delete routeModel;
}

void CustomTrip::initializeDistances() {
    int i = 1;
    ui->restComboBox->addItem("Saddleback College");
    QSqlQuery query("SELECT * FROM restaurant");
    while (query.next()) {
        ui->restComboBox->addItem(query.value(0).toString());
        for (int k = 0; k < 20; ++ k) d[i][k] = query.value(k + 2).toDouble();
        d[0][i] = d[i][0];
        ++i;
    }
}

void CustomTrip::updateTrip() {
    for (int i = 0; i < 20; ++i) isAvailable[i] = false;
    QSqlQuery query("SELECT restNum FROM trip");
    while (query.next()) isAvailable[query.value(0).toInt()] = true;

    calculateTrip(start);
}

void CustomTrip::calculateTrip(int start) {
    if (start == -1) return;

    QString restName = "";
    order.push_back(start);
    isAvailable[start] = false;
    int idx = -1;
    double dist = 999.9;

    for (int i = 0; i < 20; ++i) {
        if (isAvailable[i] && d[start][i] < dist) {
            idx = i;
            dist = d[start][i];
            }
    }

    QSqlQuery query("SELECT restName FROM restaurant WHERE restNum =\"" + QString::number(start) + "\"");
    query.next();
    restName = start == 0 ? "Saddleback College" : query.value(0).toString();
    dist = dist == 999.9 ? 0.0 : dist;

    query.exec("INSERT INTO route (restName, routeOrder, distToNext) VALUES (\"" + restName + "\", \"" + QString::number(order.size()) + "\", \"" + QString::number(dist) + "\");");
    query.next();
    calculateTrip(idx);
}

void CustomTrip::tableViewUpdate() {
    routeModel->setQuery("SELECT restName, distToNext FROM route ORDER BY routeOrder");
    ui->routeTableView->setModel(routeModel);

    tripModel->setQuery("DROP TABLE trip;");
    tripModel->setQuery("CREATE TABLE trip(restName TEXT);");
    tripModel->setQuery("INSERT INTO trip (restName) SELECT restName FROM restaurant;");
    tripModel->setQuery("DELETE FROM trip WHERE EXISTS (SELECT restName FROM route WHERE trip.restName = route.restName);");
    tripModel->setQuery("SELECT restName FROM trip");
    ui->tripTableView->setModel(tripModel);

    QSqlQuery query("SELECT SUM(X.TOTAL) FROM (SELECT distToNext as TOTAL FROM route) X;");
    if (query.next()) ui->distLabel->setText(QString::number(query.value(0).toDouble(), 'g', 7));
    if (ui->distLabel->text() == "") ui->distLabel->setText("0.00");
}
