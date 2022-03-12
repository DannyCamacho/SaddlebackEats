#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    DatabaseConnect();
    DatabaseInit();
    fileName = "fastfood.txt"; //THIS HAS BEEN EDITED FROM ../SaddlebackEats/fastfood.txt
    DatabasePopulate();
    restModel = new QSqlQueryModel;
    menuModel = new QSqlQueryModel;
    cartModel = new QSqlQueryModel;
    on_checkBox_stateChanged(0);

    ui->spinBox->setRange(1,100); //Sets the spinbox range from the default (1,99) to (1,100)
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::cartLink); //This connects the add button to the table in the inherited class, shopping cart
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::DatabaseConnect() {
    const QString DRIVER("QSQLITE");

    if(QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
        db.setDatabaseName(":memory:");

        if(!db.open()) qWarning() << "MainWindow::DatabaseConnect - ERROR: " << db.lastError().text();
    } else qWarning() << "MainWindow::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void MainWindow::DatabaseInit() {
    QSqlQuery restaurant("CREATE TABLE restaurant (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, d0 INTEGER, d1 INTEGER, d2 INTEGER, d3 INTEGER, d4 INTEGER, d5 INTEGER, d6 INTEGER, d7 INTEGER, d8 INTEGER, d9 INTEGER, d10 INTEGER, d11 INTEGER, d12 INTEGER, d13 INTEGER, d14 INTEGER, d15 INTEGER, d16 INTEGER, d17 INTEGER, d18 INTEGER, d19 INTEGER, d20 INTEGER, menuSize TEXT);");
    if(!restaurant.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << restaurant.lastError().text();

    QSqlQuery menu("CREATE TABLE menu (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, restNum INTEGER, menuItem TEXT, menuPrice INTEGER);");
    if(!menu.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << menu.lastError().text();

    QSqlQuery cart("CREATE TABLE cart (id INTEGER UNIQUE PRIMARY KEY, restName TEXT, menuItem TEXT, menuPrice INTEGER, menuCounter INTEGER);");
    if(!cart.isActive()) qWarning() << "MainWindow::DatabaseInit - ERROR: " << menu.lastError().text();
}

void MainWindow::DatabasePopulate() {
    QString q;
    QSqlQuery query;
    std::string s;
    std::string restName;
    std::string restNum;
    std::string d[11];
    std::string menuItem[10];
    std::string menuPrice[10];
    int menuSize;

    std::ifstream infile;
    infile.open(fileName);
    if (!infile) { std::cout << "Error: File not found or corrupt. " << std::endl; return; }

    while (getline(infile, restName) && getline(infile, restNum) && getline(infile, s)) {
        restName.erase(0, 30);
        restNum.erase(0, 28);

        for(int i = 1; i < 11; ++i) {
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

        s = "INSERT INTO restaurant (restName, restNum, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, menuSize) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + d[0] + "\", \"" + d[1] + "\", \"" + d[2] + "\", \"" + d[3] + "\", \"" + d[4] + "\", \"" + d[5] + "\", \"" + d[6] + "\", \"" + d[7] + "\", \"" + d[8] + "\", \"" + d[9] + "\", \"" + d[10] + "\", \"" + std::to_string(menuSize) + "\");";
        q = QString::fromStdString(s);
        if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

// FOLLOWING CODE USED FOR SQLITE TESTING PURPOSES:
//        q = "SELECT * FROM restaurant WHERE restName =\"" + QString::fromStdString(restName) + "\"";
//        query.exec(q);
//        query.next();
//        std::cout << query.value(1).toString().toStdString() << " " << query.value(2).toString().toStdString() << " " << query.value(3).toString().toStdString() << " " << query.value(4).toString().toStdString() << " " << query.value(5).toString().toStdString() << " " << query.value(6).toString().toStdString() << " " << query.value(7).toString().toStdString() << " " << query.value(8).toString().toStdString() << " " << query.value(9).toString().toStdString() << " " << query.value(10).toString().toStdString() << " " << query.value(11).toString().toStdString() << " " << query.value(12).toString().toStdString() << " " << query.value(13).toString().toStdString() << " " << query.value(14).toString().toStdString() << std::endl;

        for (int i = 0; i < menuSize; ++i) {
            s = "INSERT INTO menu (restName, restNum, menuItem, menuPrice) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + menuItem[i] + "\", \"" + menuPrice[i] + "\");";
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

void MainWindow::restTableViewUpdate(int arg1) {
    QString sort = arg1 ? "d0" : "restName";

    restModel->setQuery("SELECT restName, d0 FROM restaurant ORDER BY " + sort);
    ui->rest_tableView->setModel(restModel);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{

    restTableViewUpdate(arg1);
}

void MainWindow::on_rest_tableView_clicked(const QModelIndex &index)
{
    QString restName = index.siblingAtColumn(0).data().toString();
    restHolder = restName;
    spinHolder = ui->spinBox->value();
    menuModel->setQuery("SELECT menuItem, menuPrice FROM menu WHERE restName =\"" + restName + "\"");
    ui->menu_tableView->setModel(menuModel);
}



