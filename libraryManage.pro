#-------------------------------------------------
#
# Project created by QtCreator 2021-12-28T13:14:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libraryManage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    librarymanagemainwindow.cpp \
    librarymanageuser.cpp \
    manageuserinformation.cpp \
    pushbottonwithimg.cpp \
    addnewuser.cpp \
    returnbook.cpp \
    book.cpp \
    mylineedit.cpp \
    view.cpp \
    in.cpp \
    item.cpp

HEADERS += \
        widget.h \
    librarymanagemainwindow.h \
    librarymanageuser.h \
    manageuserinformation.h \
    pushbottonwithimg.h \
    addnewuser.h \
    returnbook.h \
    book.h \
    in.h \
    mylineedit.h \
    view.h \
    item.h

FORMS += \
        widget.ui \
    librarymanagemainwindow.ui \
    librarymanageuser.ui \
    manageuserinformation.ui \
    addnewuser.ui \
    returnbook.ui \
    in.ui \
    book.ui \
    view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    img.qrc

DISTFILES += \
    libmanageLogo.png \
    bookAdmin.pro.user \
    what.jpeg \
    what_1.jpeg \
    -2.jpeg \
    -1.jpeg \
    2a0f4afab6d3b2932a3de633e1e686d1.jpeg

SUBDIRS += \
    bookAdmin.pro
