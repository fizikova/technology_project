QT += core gui widgets network
QT += sql
CONFIG += c++17
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = GuiApp

SOURCES += \
    src/database.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/loginwindow.cpp \
    src/registerwindow.cpp \
    src/taskwindow.cpp \
    src/server.cpp \
    src/functionsforserver.cpp \
    src/chord.cpp \
    src/vigener.cpp

HEADERS += \
    src/database.h \
    src/mainwindow.h \
    src/loginwindow.h \
    src/registerwindow.h \
    src/taskwindow.h \
    src/server.h \
    src/functionsforserver.h \
    src/chord.h \
    src/vigener.h

FORMS += \
    forms/mainwindow.ui \
    forms/loginwindow.ui \
    forms/registerwindow.ui \
    forms/taskwindow.ui
