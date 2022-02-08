#include <iostream>
#include <fstream>
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
    QSqlQuery query("CREATE TABLE restaurant (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, d0 INTEGER, d1 INTEGER, d2 INTEGER, d3 INTEGER, d4 INTEGER, d5 INTEGER, d6 INTEGER, d7 INTEGER, d8 INTEGER, d9 INTEGER, d10 INTEGER, d11 INTEGER, d12 INTEGER, d13 INTEGER, d14 INTEGER, d15 INTEGER, d16 INTEGER, d17 INTEGER, d18 INTEGER, d19 INTEGER, d20 INTEGER);");

    query.prepare("CREATE TABLE menu (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, itemName TEXT, itemPrice INTEGER);");

    if(!query.isActive())
        qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
}

void MainWindow::DatabasePopulate() {
    QString q;
    QSqlQuery query;
    std::string s;
    std::string name;
    std::string d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;
    int num = 0;
    bool alreadyExist = false;

    std::ifstream infile;
        infile.open(fileName);
        if (!infile) { std::cout << "Error: File not found or corrupt. " << std::endl; return; }

    while (getline(infile, s, ':') && getline(infile, name, '\n') && getline(infile, s) && getline(infile, s) && getline(infile, location, '\t') && getline(infile, conference, '\t') && getline(infile, division, '\t') && getline(infile, surfaceType, '\t') && getline(infile, stadiumRoofType, '\t') && getline(infile, dateOpened, '\t') && getline(infile, expansion, '\n')) {
        query.prepare("SELECT * FROM restaurant WHERE restName=:restName");
        query.bindValue(":restName", QString::fromStdString(name));
        if (!query.exec()) {
            qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
        }
        alreadyExist = query.next();

        if (alreadyExist) {
            continue;
        }

        std::string s = "INSERT INTO restaurant (teamName, stadiumName, seatingCapacity, location, conference, division, surfaceType, stadiumRoofType, dateOpened, expansion) VALUES (\"" + teamName + "\", \"" + stadiumName+ "\", \"" + seatingCapacity + "\", \"" + location + "\", \"" + conference + "\", \"" + division + "\", \"" + surfaceType + "\", \"" + stadiumRoofType + "\", \"" + dateOpened + "\", \"" + expansion + "\");";
        q = QString::fromStdString(s);

        if(!query.exec(q))
            qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
    }
    infile.close();
}
