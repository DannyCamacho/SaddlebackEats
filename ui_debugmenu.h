/********************************************************************************
** Form generated from reading UI file 'debugmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGMENU_H
#define UI_DEBUGMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugMenu
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_4;
    QFrame *frame;
    QListWidget *resturantList;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label_6;
    QPushButton *removeFromList;
    QPushButton *addToList;
    QLabel *label_7;
    QFrame *frame_5;
    QLabel *label_4;
    QLineEdit *inputResturantName;
    QFrame *frame_6;
    QLabel *label_5;
    QLineEdit *inputResturantDist;
    QCheckBox *sortByDistToggle;
    QLabel *label_8;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuDebug_Meni;
    QMenu *menuLogout;
    QMenu *menuSave_List;
    QMenu *menuFile;
    QMenu *menuSave_as;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *debugMenu)
    {
        if (debugMenu->objectName().isEmpty())
            debugMenu->setObjectName(QString::fromUtf8("debugMenu"));
        debugMenu->resize(889, 557);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/resources/SE_logo_mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        debugMenu->setWindowIcon(icon);
        debugMenu->setAutoFillBackground(false);
        debugMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(debugMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 520, 121, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 251, 41));
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        label_2->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(39, 80, 511, 351));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 251, 351));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        resturantList = new QListWidget(frame);
        resturantList->setObjectName(QString::fromUtf8("resturantList"));
        resturantList->setGeometry(QRect(1, 1, 249, 349));
        resturantList->setMinimumSize(QSize(249, 349));
        resturantList->setMaximumSize(QSize(249, 349));
        QFont font1;
        font1.setPointSize(11);
        resturantList->setFont(font1);
        resturantList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        resturantList->setFrameShape(QFrame::NoFrame);
        resturantList->setFrameShadow(QFrame::Plain);
        resturantList->setLineWidth(2);
        resturantList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        resturantList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(260, 0, 251, 351));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 200, 221, 88));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 10, 51, 21));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/rec/resources/plusSign.png);"));
        removeFromList = new QPushButton(frame_3);
        removeFromList->setObjectName(QString::fromUtf8("removeFromList"));
        removeFromList->setGeometry(QRect(60, 50, 151, 24));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        removeFromList->setFont(font2);
        removeFromList->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        removeFromList->setAutoDefault(true);
        addToList = new QPushButton(frame_3);
        addToList->setObjectName(QString::fromUtf8("addToList"));
        addToList->setGeometry(QRect(60, 10, 151, 24));
        addToList->setFont(font2);
        addToList->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        addToList->setAutoDefault(true);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 52, 51, 21));
        label_7->setStyleSheet(QString::fromUtf8("image: url(:/rec/resources/removeSign.png);"));
        frame_5 = new QFrame(frame_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 70, 231, 51));
        frame_5->setFont(font1);
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Plain);
        label_4 = new QLabel(frame_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 10, 71, 31));
        QFont font3;
        font3.setPointSize(12);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        inputResturantName = new QLineEdit(frame_5);
        inputResturantName->setObjectName(QString::fromUtf8("inputResturantName"));
        inputResturantName->setGeometry(QRect(70, 10, 151, 31));
        inputResturantName->setFont(font1);
        inputResturantName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(225, 225, 225);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        frame_6 = new QFrame(frame_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(10, 130, 231, 51));
        frame_6->setFont(font1);
        frame_6->setFrameShape(QFrame::NoFrame);
        frame_6->setFrameShadow(QFrame::Plain);
        label_5 = new QLabel(frame_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 10, 71, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        inputResturantDist = new QLineEdit(frame_6);
        inputResturantDist->setObjectName(QString::fromUtf8("inputResturantDist"));
        inputResturantDist->setGeometry(QRect(70, 10, 151, 31));
        inputResturantDist->setFont(font1);
        inputResturantDist->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(225, 225, 225);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        sortByDistToggle = new QCheckBox(centralwidget);
        sortByDistToggle->setObjectName(QString::fromUtf8("sortByDistToggle"));
        sortByDistToggle->setGeometry(QRect(40, 440, 251, 21));
        sortByDistToggle->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(600, 30, 231, 101));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/rec/resources/SE_1-removebg.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 30, 251, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        debugMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(debugMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 889, 17));
        menuDebug_Meni = new QMenu(menubar);
        menuDebug_Meni->setObjectName(QString::fromUtf8("menuDebug_Meni"));
        menuLogout = new QMenu(menubar);
        menuLogout->setObjectName(QString::fromUtf8("menuLogout"));
        menuSave_List = new QMenu(menubar);
        menuSave_List->setObjectName(QString::fromUtf8("menuSave_List"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSave_as = new QMenu(menubar);
        menuSave_as->setObjectName(QString::fromUtf8("menuSave_as"));
        debugMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(debugMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        debugMenu->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSave_List->menuAction());
        menubar->addAction(menuSave_as->menuAction());
        menubar->addAction(menuDebug_Meni->menuAction());
        menubar->addAction(menuLogout->menuAction());

        retranslateUi(debugMenu);

        removeFromList->setDefault(true);
        addToList->setDefault(true);


        QMetaObject::connectSlotsByName(debugMenu);
    } // setupUi

    void retranslateUi(QMainWindow *debugMenu)
    {
        debugMenu->setWindowTitle(QCoreApplication::translate("debugMenu", "Administrative Debug Menu", nullptr));
        label->setText(QCoreApplication::translate("debugMenu", "Version 1.0", nullptr));
        label_2->setText(QCoreApplication::translate("debugMenu", "Restaurants", nullptr));
        label_6->setText(QString());
        removeFromList->setText(QCoreApplication::translate("debugMenu", "Remove Restaurant", nullptr));
        addToList->setText(QCoreApplication::translate("debugMenu", "Add Restaurant", nullptr));
        label_7->setText(QString());
        label_4->setText(QCoreApplication::translate("debugMenu", "Name", nullptr));
        inputResturantName->setText(QString());
        label_5->setText(QCoreApplication::translate("debugMenu", "Distance", nullptr));
        inputResturantDist->setText(QString());
        sortByDistToggle->setText(QCoreApplication::translate("debugMenu", "Sort by distance", nullptr));
        label_8->setText(QString());
        label_3->setText(QCoreApplication::translate("debugMenu", "Admin Options", nullptr));
        menuDebug_Meni->setTitle(QCoreApplication::translate("debugMenu", "About", nullptr));
        menuLogout->setTitle(QCoreApplication::translate("debugMenu", "Logout", nullptr));
        menuSave_List->setTitle(QCoreApplication::translate("debugMenu", "Save", nullptr));
        menuFile->setTitle(QCoreApplication::translate("debugMenu", "File", nullptr));
        menuSave_as->setTitle(QCoreApplication::translate("debugMenu", "Save as", nullptr));
    } // retranslateUi

};

namespace Ui {
    class debugMenu: public Ui_debugMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGMENU_H
