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
    isAvailable[0] = false;

    calculateTrip(start);
}

void CustomTrip::calculateTrip(int start) {
    if (start == -1) return;

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
    QString restName = query.next() ? query.value(0).toString() : "Saddleback College";
    dist = dist == 999.9 ? 0.0 : dist;

    query.exec("INSERT INTO route (restName, restNum, routeOrder, distToNext) VALUES (\"" + restName + "\", \"" + QString::number(start) + "\", \"" + QString::number(order.size()) + "\", \"" + QString::number(dist) + "\");");

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

void CustomTrip::on_pushButton_6_clicked() { // remove button
    tripModel->setQuery("DROP TABLE route;");
    tripModel->setQuery("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    MainWindow* mainWindow = new MainWindow(this);
    mainWindow->show();
    hide();
    delete ui;
}

void CustomTrip::on_tripTableView_clicked(const QModelIndex &index){
    ui->routeTableView->clearSelection();
    name = index.siblingAtColumn(0).data().toString();
}

void CustomTrip::on_routeTableView_clicked(const QModelIndex &index){
    ui->tripTableView->clearSelection();
    name = index.siblingAtColumn(0).data().toString();
}

void CustomTrip::on_pushButton_9_clicked() { // add button
    QSqlQuery query("SELECT restName FROM trip WHERE restName =\"" + name + "\";");

    if (!query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Invalid Selection","Please Select a Valid Restaurant!");
       messageBox.setFixedSize(500,200);
       return;
    }

    query.exec("SELECT restNum FROM restaurant WHERE restName =\"" + name + "\";");
    QString restNum = query.next() ? query.value(0).toString() : "0";

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");
    query.exec("INSERT INTO trip (restName, restNum) VALUES (\"" + name + "\", \"" + restNum + "\");");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

void CustomTrip::on_pushButton_10_clicked() { // remove button
    QSqlQuery query("SELECT restName FROM route WHERE restName =\"" + name + "\";");

    if (!query.next()) {
       QMessageBox messageBox;
       messageBox.critical(0,"Invalid Selection","Please Select a Valid Restaurant!");
       messageBox.setFixedSize(500,200);
       return;
    }

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");
    query.exec("DELETE FROM trip WHERE restName =\"" + name + "\";");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

void CustomTrip::on_restComboBox_currentTextChanged(const QString &arg1) {
    QSqlQuery query("SELECT restNum FROM restaurant WHERE restName =\"" + arg1 + "\";");
    start = query.next() ? query.value(0).toInt() : 0;

    query.exec("DROP TABLE trip;");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER);");
    query.exec("INSERT INTO trip (restName, restNum) SELECT restName, restNum FROM route;");

    query.exec("DROP TABLE route;");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");

    updateTrip();
    tableViewUpdate();
}

void CustomTrip::on_pushButton_3_clicked() {
    ui->restComboBox->setCurrentText("Domino's Pizza");
    on_restComboBox_currentTextChanged("Domino's Pizza");
}
