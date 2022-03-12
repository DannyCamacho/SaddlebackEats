/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRestaurants;
    QAction *actionCheckout;
    QAction *actionLogin;
    QWidget *centralwidget;
    QCheckBox *checkBox;
    QFrame *frame;
    QTableView *rest_tableView;
    QTableView *menu_tableView;
    QFrame *frame_2;
    QFrame *frame_3;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QFrame *frame_5;
    QSpinBox *spinBox;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(889, 557);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        MainWindow->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/resources/SE_logo_mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setIconSize(QSize(24, 24));
        actionRestaurants = new QAction(MainWindow);
        actionRestaurants->setObjectName(QString::fromUtf8("actionRestaurants"));
        QFont font1;
        font1.setPointSize(14);
        font1.setUnderline(false);
        actionRestaurants->setFont(font1);
        actionCheckout = new QAction(MainWindow);
        actionCheckout->setObjectName(QString::fromUtf8("actionCheckout"));
        actionCheckout->setFont(font);
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 460, 151, 19));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(159, 11, 25, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush);
#endif
        checkBox->setPalette(palette1);
        QFont font2;
        font2.setPointSize(11);
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(159, 11, 25);\n"
""));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 70, 491, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        rest_tableView = new QTableView(frame);
        rest_tableView->setObjectName(QString::fromUtf8("rest_tableView"));
        rest_tableView->setGeometry(QRect(0, 0, 241, 381));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rest_tableView->sizePolicy().hasHeightForWidth());
        rest_tableView->setSizePolicy(sizePolicy);
        rest_tableView->setFont(font2);
        rest_tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);"));
        rest_tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        rest_tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        rest_tableView->setAutoScroll(false);
        rest_tableView->setAutoScrollMargin(5);
        rest_tableView->setDragDropOverwriteMode(false);
        rest_tableView->setAlternatingRowColors(true);
        rest_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        rest_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        rest_tableView->setShowGrid(false);
        rest_tableView->setGridStyle(Qt::SolidLine);
        rest_tableView->setSortingEnabled(false);
        rest_tableView->horizontalHeader()->setVisible(false);
        rest_tableView->horizontalHeader()->setMinimumSectionSize(50);
        rest_tableView->horizontalHeader()->setDefaultSectionSize(200);
        rest_tableView->verticalHeader()->setVisible(false);
        rest_tableView->verticalHeader()->setHighlightSections(true);
        menu_tableView = new QTableView(frame);
        menu_tableView->setObjectName(QString::fromUtf8("menu_tableView"));
        menu_tableView->setGeometry(QRect(250, 0, 241, 381));
        menu_tableView->setFont(font2);
        menu_tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"alternate-background-color: rgb(225, 225, 225);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
""));
        menu_tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        menu_tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        menu_tableView->setAutoScroll(false);
        menu_tableView->setAutoScrollMargin(5);
        menu_tableView->setDragDropOverwriteMode(false);
        menu_tableView->setAlternatingRowColors(true);
        menu_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        menu_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        menu_tableView->setShowGrid(false);
        menu_tableView->horizontalHeader()->setVisible(false);
        menu_tableView->horizontalHeader()->setMinimumSectionSize(50);
        menu_tableView->horizontalHeader()->setDefaultSectionSize(200);
        menu_tableView->verticalHeader()->setVisible(false);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(620, 20, 231, 101));
        frame_2->setStyleSheet(QString::fromUtf8("image: url(:/rec/resources/SE_1-removebg.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(40, 20, 491, 41));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 5, 241, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(246, 9, 241, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(620, 260, 231, 191));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Plain);
        verticalLayoutWidget = new QWidget(frame_4);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 50, 171, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font3;
        font3.setPointSize(10);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(false);

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        pushButton_2->setAutoDefault(true);
        pushButton_2->setFlat(false);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font3);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);"));
        pushButton_3->setAutoDefault(true);
        pushButton_3->setFlat(false);

        verticalLayout->addWidget(pushButton_3);

        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 20, 171, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_3->setAlignment(Qt::AlignCenter);
        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(620, 150, 231, 80));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Plain);
        spinBox = new QSpinBox(frame_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(30, 20, 61, 41));
        spinBox->setFont(font3);
        spinBox->setFocusPolicy(Qt::NoFocus);
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(159, 11, 25);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(225, 225, 225);\n"
""));
        spinBox->setFrame(true);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setReadOnly(false);
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox->setKeyboardTracking(true);
        spinBox->setProperty("showGroupSeparator", QVariant(false));
        spinBox->setValue(1);
        pushButton_4 = new QPushButton(frame_5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(110, 20, 91, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);\n"
"color: rgb(0, 0, 0);\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/resources/addToCart-removebg-.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(30, 30));
        pushButton_4->setAutoDefault(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 889, 30));
        menubar->setFont(font);
        menubar->setContextMenuPolicy(Qt::DefaultContextMenu);
        menubar->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(170, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuMenu->setGeometry(QRect(1769, 115, 182, 167));
        menuMenu->setFont(font);
        menuMenu->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/resources/menu_icon-removebg.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuMenu->setIcon(icon2);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionRestaurants);
        menuMenu->addAction(actionCheckout);
        menuMenu->addSeparator();
        menuMenu->addAction(actionLogin);

        retranslateUi(MainWindow);

        pushButton->setDefault(true);
        pushButton_2->setDefault(true);
        pushButton_3->setDefault(true);
        pushButton_4->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Saddleback Eats", nullptr));
        actionRestaurants->setText(QCoreApplication::translate("MainWindow", "Restaurants", nullptr));
        actionCheckout->setText(QCoreApplication::translate("MainWindow", "Checkout", nullptr));
        actionLogin->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Sort by distance", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Restaurants", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Visit Initial List", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Start At Dominos", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Custom Trip", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Trip Planner", nullptr));
        pushButton_4->setText(QString());
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
