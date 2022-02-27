#ifndef DEBUGMENU_H
#define DEBUGMENU_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class debugMenu;
}

class debugMenu : public QMainWindow
{
    Q_OBJECT

public:
    // default constructor
    explicit debugMenu(QWidget *parent = nullptr);

    //destructor
    ~debugMenu();

private slots:
    void on_removeFromList_clicked();

    void on_resturantList_currentRowChanged(int currentRow);

    void on_addToList_clicked();

private:
    Ui::debugMenu *ui;

    int mnSelected = -1;
    QIcon resturantImage = QIcon(":/rec/resources/resturantImage1.png");

};

#endif // DEBUGMENU_H
