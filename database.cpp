#include "database.h"

bool Database::isInitialized = false;

Database::Database() {
    if (!isInitialized) {
        connect();
        init();
        isInitialized = true;
    }
}

void Database::connect() {
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(":memory:"); //initializes database on each run.
        //db.setDatabaseName("RestaurantDB"); // Uses RestaurantDB database

        if(!db.open()) qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    } else qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void Database::init() {
    QSqlQuery query("CREATE TABLE restaurant (restName TEXT, restNum INTEGER, d0 INTEGER, d1 INTEGER, d2 INTEGER, d3 INTEGER, d4 INTEGER, d5 INTEGER, d6 INTEGER, d7 INTEGER, d8 INTEGER, d9 INTEGER, d10 INTEGER, d11 INTEGER, d12 INTEGER, d13 INTEGER, d14 INTEGER, d15 INTEGER, d16 INTEGER, d17 INTEGER, d18 INTEGER, d19 INTEGER, d20 INTEGER, menuSize TEXT);");
    if(!query.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << query.lastError().text();
    query.exec("CREATE TABLE menu (restName TEXT, menuItem TEXT, menuPrice INTEGER);");
    query.exec("CREATE TABLE cart (restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER, quantity INTEGER);");
    query.exec("CREATE TABLE trip (restName TEXT, restNum INTEGER, total INTEGER);");
    query.exec("CREATE TABLE route (restName TEXT, restNum INTEGER, routeOrder INTEGER, distToNext INTEGER);");
}

void Database::populate(std::string fileName) {
    QString q;
    QSqlQuery query;
    std::string s;
    std::string restName;
    std::string restNum;
    std::string d[20];
    std::string menuItem[10];
    std::string menuPrice[10];
    int menuSize;

    std::ifstream infile;
    infile.open(fileName);
    if (!infile) { std::cout << "Error: File not found or corrupt. " << std::endl; return; }

    while (getline(infile, restName) && getline(infile, restNum) && getline(infile, s)) {
        restName.erase(0, 30);
        restNum.erase(0, 28);
        int n = stoi(s.erase(0,50));

        for(int i = 1; i < n + 1; ++i) {
            getline(infile, s, ' ');
            getline(infile, d[i]);
        } getline(infile, d[0], ' ');
        getline(infile, s);
        getline(infile, s, ' ');
        menuSize = std::stoi(s);
        getline(infile, s);

        for(int i = 0; i < menuSize; ++i) {
            getline(infile, menuItem[i]);
            getline(infile, menuPrice[i]);
        } getline(infile, s);

        query.prepare("SELECT * FROM restaurant WHERE restName=:restName");
        query.bindValue(":restName", QString::fromStdString(restName));
        if (!query.exec()) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
        if (query.next()) continue;

        s = "INSERT INTO restaurant (restName, restNum, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, menuSize) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + d[0] + "\", \"" + d[1] + "\", \"" + d[2] + "\", \"" + d[3] + "\", \"" + d[4] + "\", \"" + d[5] + "\", \"" + d[6] + "\", \"" + d[7] + "\", \"" + d[8] + "\", \"" + d[9] + "\", \"" + d[10] + "\", \"" + std::to_string(menuSize) + "\");";
        q = QString::fromStdString(s);
        if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//        q = "SELECT * FROM restaurant WHERE restName =\"" + QString::fromStdString(restName) + "\"";
//        query.exec(q);
//        query.next();
//        std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << " " << query.value(5).toString().toStdString() << " " << query.value(6).toString().toStdString() << " " << query.value(7).toString().toStdString() << " " << query.value(8).toString().toStdString() << " " << query.value(9).toString().toStdString() << " " << query.value(10).toString().toStdString() << " " << query.value(11).toString().toStdString() << " " << query.value(12).toString().toStdString() << " " << query.value(13).toString().toStdString() << " " << query.value(14).toString().toStdString() << std::endl;

        for (int i = 0; i < menuSize; ++i) {
            s = "INSERT INTO menu (restName, menuItem, menuPrice) VALUES (\"" + restName + "\", \"" + menuItem[i] + "\", \"" + menuPrice[i] + "\");";
            q = QString::fromStdString(s);
            if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//            q = "SELECT * FROM menu WHERE menuItem =\"" + QString::fromStdString(menuItem[i]) + "\" AND restNum =\"" + QString::fromStdString(restNum)+ "\"";
//            query.exec(q);
//            query.next();
//            std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << std::endl;
        }
    } infile.close();
}

void Database::import(std::string fileName) {
    QString q;
    QSqlQuery query;
    std::string s;
    std::string restName;
    std::string restNum;
    std::string d[20];
    std::string menuItem[10];
    std::string menuPrice[10];
    int menuSize;

    std::ifstream infile;
    infile.open(fileName);
    if (!infile) { std::cout << "Error: File not found or corrupt. " << std::endl; return; }

    while (getline(infile, restName) && getline(infile, restNum) && getline(infile, s)) {
        restName.erase(0, 30);
        restNum.erase(0, 28);
        int n = stoi(s.erase(0,50));

        for(int i = 1; i < n + 1; ++i) {
            getline(infile, s, ' ');
            getline(infile, d[i]);
        } getline(infile, d[0], ' ');
        getline(infile, s);
        getline(infile, s, ' ');
        menuSize = std::stoi(s);
        getline(infile, s);

        for(int i = 0; i < menuSize; ++i) {
            getline(infile, menuItem[i]);
            getline(infile, menuPrice[i]);
        } getline(infile, s);

        query.prepare("SELECT * FROM restaurant WHERE restName=:restName");
        query.bindValue(":restName", QString::fromStdString(restName));
        if (!query.exec()) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
        if (query.next()) continue;

        s = "INSERT INTO restaurant (restName, restNum, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, menuSize) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + d[0] + "\", \"" + d[1] + "\", \"" + d[2] + "\", \"" + d[3] + "\", \"" + d[4] + "\", \"" + d[5] + "\", \"" + d[6] + "\", \"" + d[7] + "\", \"" + d[8] + "\", \"" + d[9] + "\", \"" + d[10] + "\", \"" + d[11] + "\", \"" + d[12] + "\", \"" + std::to_string(menuSize) + "\");";
        q = QString::fromStdString(s);
        if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

        for (int i = 1; i < 11; ++i) {
            s = "UPDATE restaurant SET d" + restNum + "= \"" + d[i] + "\" WHERE restNum = " + std::to_string(i) + ";";
            q = QString::fromStdString(s);
            if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();
        }

// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//        q = "SELECT * FROM restaurant WHERE restName =\"" + QString::fromStdString(restName) + "\"";
//        query.exec(q);
//        query.next();
//        std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << " " << query.value(5).toString().toStdString() << " " << query.value(6).toString().toStdString() << " " << query.value(7).toString().toStdString() << " " << query.value(8).toString().toStdString() << " " << query.value(9).toString().toStdString() << " " << query.value(10).toString().toStdString() << " " << query.value(11).toString().toStdString() << " " << query.value(12).toString().toStdString() << " " << query.value(13).toString().toStdString() << " " << query.value(14).toString().toStdString() << " " << query.value(15).toString().toStdString() << std::endl;

        for (int i = 0; i < menuSize; ++i) {
            s = "INSERT INTO menu (restName, menuItem, menuPrice) VALUES (\"" + restName + "\", \"" + menuItem[i] + "\", \"" + menuPrice[i] + "\");";
            q = QString::fromStdString(s);
            if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//            q = "SELECT * FROM menu WHERE menuItem =\"" + QString::fromStdString(menuItem[i]) + "\" AND restNum =\"" + QString::fromStdString(restNum)+ "\"";
//            query.exec(q);
//            query.next();
//            std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << std::endl;
        }
    } infile.close();
// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//    q = "SELECT * FROM restaurant ORDER BY restNum";
//    query.exec(q);
//    while (query.next())
//        std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << " " << query.value(5).toString().toStdString() << " " << query.value(6).toString().toStdString() << " " << query.value(7).toString().toStdString() << " " << query.value(8).toString().toStdString() << " " << query.value(9).toString().toStdString() << " " << query.value(10).toString().toStdString() << " " << query.value(11).toString().toStdString() << " " << query.value(12).toString().toStdString() << " " << query.value(13).toString().toStdString() << " " << query.value(14).toString().toStdString() << " " << query.value(15).toString().toStdString() << std::endl;
}
