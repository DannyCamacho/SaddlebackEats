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


    printDistance(0, ui->resturantList);
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


void debugMenu::on_sortByDistToggle_toggled(bool checked)
{
    ui->resturantList->clear();
    printDistance(checked, ui->resturantList);

}

