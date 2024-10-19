QT += core gui testlib widgets
TEMPLATE = app
TARGET = test_app

# Пути к исходным файлам
SOURCES += \
    ../client/src/sha384form.cpp \
    ../tests/test_sha384form.cpp

# Пути к заголовочным файлам
HEADERS += \
    ../client/include/sha384form.h

# Включение UI файлов
FORMS += \
    ../client/ui/sha384form.ui

# Указываем путь к заголовочным файлам
INCLUDEPATH += ../client/include
