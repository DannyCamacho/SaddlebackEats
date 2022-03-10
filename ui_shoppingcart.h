/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shoppingCart
{
public:
    QWidget *centralwidget;
    QTableView *restTable;
    QTableView *itemTable;
    QLabel *restList;
    QLabel *itemList;
    QTableView *tableView_3;
    QLabel *receipt;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *shoppingCart)
    {
        if (shoppingCart->objectName().isEmpty())
            shoppingCart->setObjectName(QString::fromUtf8("shoppingCart"));
        shoppingCart->resize(800, 600);
        centralwidget = new QWidget(shoppingCart);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        restTable = new QTableView(centralwidget);
        restTable->setObjectName(QString::fromUtf8("restTable"));
        restTable->setGeometry(QRect(20, 120, 241, 431));
        restTable->setFrameShape(QFrame::StyledPanel);
        itemTable = new QTableView(centralwidget);
        itemTable->setObjectName(QString::fromUtf8("itemTable"));
        itemTable->setGeometry(QRect(280, 120, 231, 431));
        restList = new QLabel(centralwidget);
        restList->setObjectName(QString::fromUtf8("restList"));
        restList->setGeometry(QRect(20, 91, 241, 20));
        restList->setLayoutDirection(Qt::LeftToRight);
        restList->setFrameShape(QFrame::Box);
        restList->setAlignment(Qt::AlignCenter);
        itemList = new QLabel(centralwidget);
        itemList->setObjectName(QString::fromUtf8("itemList"));
        itemList->setGeometry(QRect(280, 90, 231, 21));
        itemList->setFrameShape(QFrame::Box);
        itemList->setAlignment(Qt::AlignCenter);
        tableView_3 = new QTableView(centralwidget);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(530, 120, 256, 431));
        receipt = new QLabel(centralwidget);
        receipt->setObjectName(QString::fromUtf8("receipt"));
        receipt->setGeometry(QRect(536, 90, 241, 21));
        receipt->setFrameShape(QFrame::Box);
        receipt->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 20, 251, 41));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        shoppingCart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shoppingCart);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        shoppingCart->setMenuBar(menubar);
        statusbar = new QStatusBar(shoppingCart);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        shoppingCart->setStatusBar(statusbar);

        retranslateUi(shoppingCart);

        QMetaObject::connectSlotsByName(shoppingCart);
    } // setupUi

    void retranslateUi(QMainWindow *shoppingCart)
    {
        shoppingCart->setWindowTitle(QCoreApplication::translate("shoppingCart", "MainWindow", nullptr));
        restList->setText(QCoreApplication::translate("shoppingCart", "Restaurants in Shopping Cart", nullptr));
        itemList->setText(QCoreApplication::translate("shoppingCart", "Menu Items in Shopping Cart", nullptr));
        receipt->setText(QCoreApplication::translate("shoppingCart", "Receipt", nullptr));
        label->setText(QCoreApplication::translate("shoppingCart", "Shopping Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shoppingCart: public Ui_shoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
