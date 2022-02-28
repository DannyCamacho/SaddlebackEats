#include "debugmenu.h"
#include "ui_debugmenu.h"

debugMenu::debugMenu(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::debugMenu)
{
    ui->setupUi(this);

    // sets all header text to read only
    //ui->listTitleText->setReadOnly(true);

    // assigns QPix image to green plus sign
    QPixmap addPix(":/rec/resources/plusSign.png");
    addPix = addPix.scaled(30, 30);
    ui->addLabel->setPixmap(addPix);

     // assigns QPix image to red x sign
    QPixmap removePix(":/rec/resources/removeSign.png");
    removePix = removePix.scaled(40, 40);
    ui->removeLabel->setPixmap(removePix);

    // prints out initial list
    printDistance(0, ui->resturantList);
};


debugMenu::~debugMenu()
{
    delete ui;
}

// helper function - takes in a name/di
string getRestName(string longString)
{
    int index = 0;
    bool foundInt = false;

    while (index < longString.length() && foundInt == false)
    {
        if(isdigit(longString[index]))
        {
            foundInt = true;
        }
        index++;
    }

    longString.resize(index - 4);
    return longString;
}

// This romoves the currently selected resturant from the list
// Crashes if no resturant is selected - add an exception throw or error check
void debugMenu::on_removeFromList_clicked()
{
   QSqlQuery query;
   std::string firstWord;
   QListWidgetItem *it = ui->resturantList->takeItem(mnSelected);
   string removeName = it->text().toStdString();

   // returns the resturant name by cutting the string
   firstWord = getRestName(removeName);

   // Uses a SQL statement to remove the chosen resturant fromt he list
   string c = "DELETE FROM restaurant WHERE restName=\"" + firstWord + "\";";
   QString q = QString::fromStdString(c);
   query.exec(q);

   // list is printed then cleared
   ui->resturantList->clear();
   printDistance(isSorted, ui->resturantList);
}

void debugMenu::on_resturantList_currentRowChanged(int currentRow)
{
    // assignes current slected list row
    mnSelected = currentRow;
}


// Button that adds a resturant the SQL database
// NEED to add duplicate name check!!!
void debugMenu::on_addToList_clicked()
{
    QString q;
    string s;
    string inputName = ui->inputResturantName->text().toStdString();
    string inputDist = ui->inputResturantDist->text().toStdString();

    // if the text box is empty button will not work
    if(inputName == "" || inputName == "")
        return;


    int sqlListSize = 0;
    std::string menuItem[10];
    std::string menuPrice[10];
    std::string restNum = "0";
    QSqlQuery query;

    query.exec("SELECT COUNT(N) FROM restaurant;");
    if (query.next()) {
        sqlListSize = query.value(0).toInt();
    }

//    s = "INSERT INTO restaurant (restName, restNum, d0, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, menuSize) VALUES (\"" + restName + "\", \"" + restNum + "\", \"" + d[0] + "\", \"" + d[1] + "\", \"" + d[2] + "\", \"" + d[3] + "\", \"" + d[4] + "\", \"" + d[5] + "\", \"" + d[6] + "\", \"" + d[7] + "\", \"" + d[8] + "\", \"" + d[9] + "\", \"" + d[10] + "\", \"" + std::to_string(menuSize) + "\");";
    s = "INSERT INTO restaurant (restName, restNum, d0) VALUES (\"" + inputName + "\", \"" + to_string(sqlListSize + 1) + "\", \"" + inputDist + "\");";
    q = QString::fromStdString(s);
    if (!query.exec(q)) qWarning() << "MainWindow::DatabasePopulate - ERROR: " << query.lastError().text();

    ui->resturantList->clear();
    printDistance(isSorted, ui->resturantList);
}


void debugMenu::on_sortByDistToggle_toggled(bool checked)
{
    isSorted = checked;

    ui->resturantList->clear();
    printDistance(isSorted, ui->resturantList);
}

