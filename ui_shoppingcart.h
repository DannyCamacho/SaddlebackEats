/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *restLabel;
    QLabel *itemLabel;
    QLabel *receiptLabel;
    QLabel *title;
    QPushButton *buyButton;
    QListWidget *receiptList;
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
        restTable->setGeometry(QRect(20, 120, 241, 401));
        restTable->setFrameShape(QFrame::StyledPanel);
        itemTable = new QTableView(centralwidget);
        itemTable->setObjectName(QString::fromUtf8("itemTable"));
        itemTable->setGeometry(QRect(280, 120, 231, 401));
        restLabel = new QLabel(centralwidget);
        restLabel->setObjectName(QString::fromUtf8("restLabel"));
        restLabel->setGeometry(QRect(20, 91, 241, 20));
        restLabel->setLayoutDirection(Qt::LeftToRight);
        restLabel->setFrameShape(QFrame::Box);
        restLabel->setAlignment(Qt::AlignCenter);
        itemLabel = new QLabel(centralwidget);
        itemLabel->setObjectName(QString::fromUtf8("itemLabel"));
        itemLabel->setGeometry(QRect(280, 90, 231, 21));
        itemLabel->setFrameShape(QFrame::Box);
        itemLabel->setAlignment(Qt::AlignCenter);
        receiptLabel = new QLabel(centralwidget);
        receiptLabel->setObjectName(QString::fromUtf8("receiptLabel"));
        receiptLabel->setGeometry(QRect(536, 90, 241, 21));
        receiptLabel->setFrameShape(QFrame::Box);
        receiptLabel->setAlignment(Qt::AlignCenter);
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(270, 20, 251, 41));
        title->setFrameShape(QFrame::Box);
        title->setAlignment(Qt::AlignCenter);
        buyButton = new QPushButton(centralwidget);
        buyButton->setObjectName(QString::fromUtf8("buyButton"));
        buyButton->setGeometry(QRect(19, 530, 121, 21));
        receiptList = new QListWidget(centralwidget);
        receiptList->setObjectName(QString::fromUtf8("receiptList"));
        receiptList->setGeometry(QRect(535, 120, 241, 401));
        shoppingCart->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shoppingCart);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
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
        restLabel->setText(QCoreApplication::translate("shoppingCart", "Restaurants in Shopping Cart", nullptr));
        itemLabel->setText(QCoreApplication::translate("shoppingCart", "Menu Items in Shopping Cart", nullptr));
        receiptLabel->setText(QCoreApplication::translate("shoppingCart", "Receipt", nullptr));
        title->setText(QCoreApplication::translate("shoppingCart", "Shopping Cart", nullptr));
        buyButton->setText(QCoreApplication::translate("shoppingCart", "Make Purchase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shoppingCart: public Ui_shoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
