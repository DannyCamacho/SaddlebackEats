#include "debugmenu.h"
#include "ui_debugmenu.h"

debugMenu::debugMenu(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::debugMenu)
{
    ui->setupUi(this);

    // sets all header text to read only
    ui->listTitleText->setReadOnly(true);

    // assigns QPix image to green plus sign
    QPixmap addPix(":/rec/resources/plusSign.png");
    addPix = addPix.scaled(30, 30);
    ui->addLabel->setPixmap(addPix);

     // assigns QPix image to red x sign
    QPixmap removePix(":/rec/resources/removeSign.png");
    removePix = removePix.scaled(40, 40);
    ui->removeLabel->setPixmap(removePix);

    // adds test obj to list
    // This list needs to be connected to the SQL database
//    QListWidgetItem* item1 = new QListWidgetItem(resturantImage, "Test Item 1");
//    ui->resturantList->addItem(item1);

//    QListWidgetItem* item2 = new QListWidgetItem(resturantImage, "Test Item 2");
//    ui->resturantList->addItem(item2);

//    QListWidgetItem* item3 = new QListWidgetItem(resturantImage, "Test Item 3");
//    ui->resturantList->addItem(item3);

//    QListWidgetItem* item4 = new QListWidgetItem(resturantImage, "Test Item 4");
//    ui->resturantList->addItem(item4);

    printDistance(ui->resturantList);
};


debugMenu::~debugMenu()
{
    delete ui;
}


// This romoves the currently selected resturant from the list
void debugMenu::on_removeFromList_clicked()
{
   QListWidgetItem *it = ui->resturantList->takeItem(mnSelected);
   delete it;
}

void debugMenu::on_resturantList_currentRowChanged(int currentRow)
{
    mnSelected = currentRow;
}


// Button that adds a resturant the SQL database
void debugMenu::on_addToList_clicked()
{
    QString inputName = ui->inputResturantName->text();

    // if the text box is empty button will not work
    if(inputName == "")
        return;

    QListWidgetItem* newItem = new QListWidgetItem(resturantImage, inputName);
    ui->resturantList->addItem(newItem);
}

