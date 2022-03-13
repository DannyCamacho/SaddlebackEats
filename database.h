#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Database {
public:
    Database();
    void populate(std::string fileName);
    void import(std::string fileName);

private:
    void connect();
    void init();
    static bool isInitialized;
};

#endif // DATABASE_H
