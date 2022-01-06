#-------------------------------------------------
#
# Project created by QtCreator 2021-12-28T12:29:06
#
#-------------------------------------------------

QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibManagement
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
    bookinformation.cpp \
        logindialog.cpp \
    registerdialog.cpp \
    searchwidget.cpp \
    mainpagewidget.cpp \
    mewidget.cpp \
    user.cpp \
    book.cpp \
    libmanagement.cpp \
    addnewuser.cpp \
    borrowbook.cpp \
    in.cpp \
    item.cpp \
    librarymanagemainwindow.cpp \
    librarymanageuser.cpp \
    manageuserinformation.cpp \
    mylineedit.cpp \
    pushbottonwithimg.cpp \
    returnbook.cpp \
    view.cpp \
    widget.cpp \
    main.cpp

HEADERS += \
    bookinformation.h \
        logindialog.h \
    registerdialog.h \
    libmanagement.h \
    searchwidget.h \
    mainpagewidget.h \
    mewidget.h \
    user.h \
    book.h \
    addnewuser.h \
    borrowbook.h \
    in.h \
    item.h \
    librarymanagemainwindow.h \
    librarymanageuser.h \
    manageuserinformation.h \
    mylineedit.h \
    pushbottonwithimg.h \
    returnbook.h \
    view.h \
    widget.h

FORMS += \
    bookinformation.ui \
    registerdialog.ui \
    logindialog.ui \
    libmanagement.ui \
    searchwidget.ui \
    mainpagewidget.ui \
    mewidget.ui \
    addnewuser.ui \
    book.ui \
    borrowbook.ui \
    in.ui \
    librarymanagemainwindow.ui \
    librarymanageuser.ui \
    manageuserinformation.ui \
    returnbook.ui \
    view.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    img.qrc \
    res.qrc

DISTFILES += \
    icon.ico \
    LibManagement.rc \
    bookAdmin.pro.user \
    libraryManage.pro.user \
    -1.jpeg \
    -2.jpeg \
    2a0f4afab6d3b2932a3de633e1e686d1.jpeg \
    666.jpg \
    what.jpeg \
    what_1.jpeg \
    add.png \
    book.png \
    booklogo.png \
    cancellation.png \
    confirm.png \
    exit.png \
    getIn.png \
    getOut.png \
    help.png \
    libmanageLogo.png \
    libraryManagementSystem.png \
    man.png \
    manager.png \
    messagebox.png \
    modify.png \
    search.png \
    userlogo.png \
    woman.png

RC_FILE = \
  LibManagement.rc

SUBDIRS += \
    bookAdmin.pro \
    libraryManage.pro
