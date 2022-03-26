QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customtrip.cpp \
    database.cpp \
    debugmenu.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    shoppingcart.cpp

HEADERS += \
    customtrip.h \
    database.h \
    debugmenu.h \
    login.h \
    mainwindow.h \
    shoppingcart.h

FORMS += \
    customtrip.ui \
    debugmenu.ui \
    login.ui \
    mainwindow.ui \
    receipt.ui \
    shoppingcart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    UIGraphics.qrc \
    UIGraphics.qrc

DISTFILES += \
    .gitignore \
    CS1D Spring 2022 New Fast Food Project.txt \
    README.md \
    fastfood.txt \
    resources/SE_1-removebg.png \
    resources/SE_logo.png \
    resources/SE_logo_mini.png \
    resources/addToCart-removebg-.png \
    resources/bubble-icon-removebg.png \
    resources/menu_icon-removebg.png \
    resources/plusSign.png \
    resources/removeSign.png \
    resources/resturantImage1.png \
    resources/return-icon-removebg.png \
    resources/shopping-cart-icon-SE-color-removebg.png \
    resources/shopping-cart-icon-removebg.png
