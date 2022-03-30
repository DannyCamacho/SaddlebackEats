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
     *  Constructor used to connect and initialize the SQLite databases. Singleton model used to initialize the database, after first initialization the database does not reinitialize instances.
     */
    Database();

    /*! @fn void populate(std::string fileName)
     *
     *  Method used to populate the database from file, checks for issues within the database and duplicate entries between the existing table and the current restaurant selected within file.
     *  @param std::string fileName
     */
    void populate(std::string fileName);

    /*! @fn void import(std::string fileName)
     *
     *  Method used to import new entries from file, checks for issues within the database and duplicate entries between the existing table and the current restaurant selected within file.
     *  @param std::string fileName
     */
    void import(std::string fileName);

private:
    /*! @fn connect()
     *
     *  Method used to connect connect to the SQLite database. Comment out one of the two setDatabaseNames depending on program usage. Checks for connection issues after attempting to establish the connection.
     */
    void connect();

    /*! @fn init()
     *
     *  Method used to initialize the tables used within the SQLite database. these tables are restaurant, menu, cart, trip, and route.
     */
    void init();

    /*! @var static bool isInitialized
     *  Private static member used to allow only allow one connect/init method call across all Database instances. Initialized to false to allow the first constructor to execute the connect and init methods.
     */
    static bool isInitialized;
};

#endif // DATABASE_H
