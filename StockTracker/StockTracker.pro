TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    csv_handler.cpp

HEADERS += \
    csv_handler.hh

DISTFILES += \
    Imports/Helsinki_1-51.csv
