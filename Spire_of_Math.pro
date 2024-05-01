QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attackicon.cpp \
    card.cpp \
    checkcharacter.cpp \
    choosecharacterscene.cpp \
    choosecharacterwindow2.cpp \
    gamewindow.cpp \
    handcards.cpp \
    handcardsshowscene.cpp \
    heart.cpp \
    ink.cpp \
    lose.cpp \
    main.cpp \
    mainwindow.cpp \
    money.cpp \
    mypushbtn.cpp \
    player.cpp \
    shopscene.cpp \
    stationerywidget.cpp \
    topwidegt.cpp \
    victory.cpp

HEADERS += \
    attackicon.h \
    card.h \
    checkcharacter.h \
    choosecharacterscene.h \
    choosecharacterwindow2.h \
    gamewindow.h \
    handcards.h \
    handcardsshowscene.h \
    heart.h \
    ink.h \
    lose.h \
    mainwindow.h \
    money.h \
    mypushbtn.h \
    player.h \
    shopscene.h \
    stationerywidget.h \
    topwidegt.h \
    victory.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
