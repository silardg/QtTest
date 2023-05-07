TEMPLATE = app
TARGET = addressBook

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    addressbook.cpp \
    main.cpp

HEADERS += \
    addressbook.h
