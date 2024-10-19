QT       += core gui network

TARGET = client_app
TEMPLATE = app

# Включаем необходимые модули
QT += widgets

# Исходные файлы проекта
SOURCES += \
    src/functionmenu.cpp \
    src/main.cpp \
    src/mainmenu.cpp \
    src/login.cpp \
    src/register.cpp \
    src/hordmethod.cpp \
    src/imageembed.cpp \
    src/sha384form.cpp \
    src/vigenerecipher.cpp

# Заголовочные файлы проекта
HEADERS += \
    include/functionmenu.h \
    include/mainmenu.h \
    include/login.h \
    include/register.h \
    include/hordmethod.h \
    include/imageembed.h \
    include/sha384form.h \
    include/vigenerecipher.h

# UI файлы, созданные в Qt Designer
FORMS += \
    ui/main_menu.ui \
    ui/login.ui \
    ui/register.ui \
    ui/hord_method.ui \
    ui/image_embed.ui \
    ui/functionmenu.ui \
    ui/vigenerecipher.ui \
    ui/sha384form.ui
# Ресурсы (если есть), например, изображения или другие статические файлы
# RESOURCES += resources.qrc

# Определение путей для исходных файлов, заголовков и UI файлов
INCLUDEPATH += include
