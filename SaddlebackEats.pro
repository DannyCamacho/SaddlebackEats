QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    debugmenu.cpp \
    main.cpp \
    mainwindow.cpp
    debugmenu.cpp.cpp

HEADERS += \
    debugmenu.h \
    mainwindow.h
    debugmenu.h

FORMS += \
    debugmenu.ui \
    mainwindow.ui
    debugmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    UIGraphics.qrc \
    UIGraphics.qrc

DISTFILES += \
    .gitignore \
    README.md \
    fastfood.txt \
    resources/plusSign.png \
    resources/removeSign.png \
    resources/resturantImage1.png
