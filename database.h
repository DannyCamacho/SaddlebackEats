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

/*! \class Database
 *  \brief Handles SQLite
 *  This class takes care of SQL in populating a list from an inputfile
 *
 */
class Database {
public:

    /*! Constructor
     *
     *  Checks isInitialized, if true then execute connect() then init()
     */
    Database();

    /*! @fn void populate(std::string fileName)
     *
     *  populates the database according to the input file
     *  @param std::string fileName
     */
    void populate(std::string fileName);

    /*! @fn void import(std::string fileName)
     *
     *  imports data from an input file into a database
     *  @param std::string fileName
     */
    void import(std::string fileName);

private:
    /*! @fn connect()
     *
     *  Connects to the QSqlDatabase
     */
    void connect();

    /*! @fn init()
     *
     *  initializes the restaurant, menu, and cart database
     */
    void init();

    /*! @var static bool isInitialized
     *  True if initialized, false if otherwise
     */
    static bool isInitialized;
};

#endif // DATABASE_H
