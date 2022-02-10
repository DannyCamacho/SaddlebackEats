#include <iostream>
#include <fstream>
#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    DatabaseConnect();
    DatabaseInit();
    fileName = "fastfood.txt";
    DatabasePopulate();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::DatabaseConnect() {
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName(":memory:");

        if(!db.open())
            qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    } else
        qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void MainWindow::DatabaseInit() {
    QSqlQuery restaurant("CREATE TABLE restaurant (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, d0 INTEGER, d1 INTEGER, d2 INTEGER, d3 INTEGER, d4 INTEGER, d5 INTEGER, d6 INTEGER, d7 INTEGER, d8 INTEGER, d9 INTEGER, d10 INTEGER, d11 INTEGER, d12 INTEGER, d13 INTEGER, d14 INTEGER, d15 INTEGER, d16 INTEGER, d17 INTEGER, d18 INTEGER, d19 INTEGER, d20 INTEGER, menuSize TEXT);");
    if(!restaurant.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << restaurant.lastError().text();

    QSqlQuery menu("CREATE TABLE menu (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER);");
    if(!menu.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << menu.lastError().text();
}

void MainWindow::DatabasePopulate() {
    QString q;
    QSqlQuery query;
    std::string s;
    std::string restName;
    std::string restNum;
    std::string distance[11];
    int menuSize;
    std::string menuItem[10];
    std::string menuPrice[10];

    std::ifstream infile;
    infile.open(fileName);
    if (!infile) { std::cout << "Error: File not found or corrupt. " << std::endl; return; }

    while (getline(infile, restName) && getline(infile, restNum) && getline(infile, s)) {
        restName.erase(0, 30);
        restNum.erase(0, 28);
        for(int i = 1; i < 11; ++i) {
            getline(infile, s, ' ');
            getline(infile, distance[i]);
        }
        getline(infile, distance[0], ' ');
        getline(infile, s);
        getline(infile, s, ' ');
        menuSize = std::stoi(s);
        getline(infile, s);

        for(int i = 0; i < menuSize; ++i) {
            getline(infile, menuItem[i]);
            getline(infile, menuPrice[i]);
        } getline(infile, s);

        s = "INSERT INTO restaurant (restName, restNum, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, menuSize) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + distance[0] + "\", \"" + distance[1] + "\", \"" + distance[2] + "\", \"" + distance[3] + "\", \"" + distance[4] + "\", \"" + distance[5] + "\", \"" + distance[6] + "\", \"" + distance[7] + "\", \"" + distance[8] + "\", \"" + distance[9] + "\", \"" + distance[10] + "\", \"" + std::to_string(menuSize) + "\");";
        q = QString::fromStdString(s);

        if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

        for (int i = 0; i < menuSize; ++i) {
            s = "INSERT INTO menu (restName, restNum, menuItem, menuPrice) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + menuItem[i] + "\", \"" + menuPrice[i] + "\");";
            q = QString::fromStdString(s);

            if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
        }

        q = "SELECT * FROM restaurant WHERE restName =\"" + QString::fromStdString(restName) + "\"";
        query.exec(q);
        query.next();
        std::cout << restName << " " << restNum << " " << distance[7] << " " << menuSize << " " << menuItem[2] << " " << menuPrice[2] << std::endl;
        //std::cout << query.value(1).toStdString();

    } infile.close();

}
