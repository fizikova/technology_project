QT += core gui testlib widgets
TEMPLATE = app
TARGET = test_app

# Пути к исходным файлам
SOURCES += \
    ../client/src/vigenerecipher.cpp \
    ../tests/test_vigenerecipher.cpp

# Пути к заголовочным файлам
HEADERS += \
    ../client/include/vigenerecipher.h

# Включение UI файлов
FORMS += \
    ../client/ui/vigenerecipher.ui

# Указываем путь к заголовочным файлам
INCLUDEPATH += ../client/include
