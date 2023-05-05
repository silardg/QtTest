TEMPLATE = app
TARGET = basics_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mywindow.cpp

DISTFILES += \
    README.md \
    content/logo.png

RESOURCES += \
    resources.qrc

HEADERS += \
    configuration.h \
    mywindow.h
