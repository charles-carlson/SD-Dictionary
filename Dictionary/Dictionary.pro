#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T19:47:47
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp mainwindow.cpp

HEADERS  += mainwindow.h

RESOURCES += \
    dictionary.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/uitools/dictionary
INSTALLS += target
