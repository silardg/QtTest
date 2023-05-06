TEMPLATE = app
TARGET = layout_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DISTFILES += \
    README.md

SOURCES += \
    main.cpp
