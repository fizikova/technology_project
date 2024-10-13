QT       += core gui network

TARGET = client_app
TEMPLATE = app

# Включаем необходимые модули
QT += widgets

# Исходные файлы проекта
SOURCES += \
    src/main.cpp \
    src/mainmenu.cpp \
    src/login.cpp \
    src/register.cpp \
    src/hordmethod.cpp \
    src/imageembed.cpp

# Заголовочные файлы проекта
HEADERS += \
    include/mainmenu.h \
    include/login.h \
    include/register.h \
    include/hordmethod.h \
    include/imageembed.h

# UI файлы, созданные в Qt Designer
FORMS += \
    ui/main_menu.ui \
    ui/login.ui \
    ui/register.ui \
    ui/hord_method.ui \
    ui/image_embed.ui

# Ресурсы (если есть), например, изображения или другие статические файлы
# RESOURCES += resources.qrc

# Определение путей для исходных файлов, заголовков и UI файлов
INCLUDEPATH += include
