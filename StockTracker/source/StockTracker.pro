TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    csv_handler.cpp \

HEADERS += \
    csv_handler.hh \


DISTFILES += \
    Imports/omxh.csv
