#include <QApplication>
#include <QStackedWidget>
#include "mainmenu.h"
#include "login.h"
#include "register.h"
#include "hordmethod.h"
#include "imageembed.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Создаём QStackedWidget для переключения между окнами
    QStackedWidget stackedWidget;

    // Создаём все окна
    MainMenu *mainMenu = new MainMenu();
    LoginForm *loginForm = new LoginForm();
    RegisterForm *registerForm = new RegisterForm();
    HordMethodForm *hordMethodForm = new HordMethodForm();
    ImageEmbedForm *imageEmbedForm = new ImageEmbedForm();

    // Добавляем окна в стек виджетов
    stackedWidget.addWidget(mainMenu);
    stackedWidget.addWidget(loginForm);
    stackedWidget.addWidget(registerForm);
    stackedWidget.addWidget(hordMethodForm);
    stackedWidget.addWidget(imageEmbedForm);

    // Переключение между окнами при помощи сигналов и слотов
    QObject::connect(mainMenu, &MainMenu::openLoginForm, [&]() {
        stackedWidget.setCurrentWidget(loginForm);
    });

    QObject::connect(mainMenu, &MainMenu::openRegisterForm, [&]() {
        stackedWidget.setCurrentWidget(registerForm);
    });

    QObject::connect(loginForm, &LoginForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    QObject::connect(registerForm, &RegisterForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    QObject::connect(hordMethodForm, &HordMethodForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    QObject::connect(imageEmbedForm, &ImageEmbedForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    // Устанавливаем главное окно как начальное
    stackedWidget.setCurrentWidget(mainMenu);
    stackedWidget.resize(400, 300);  // Размер окна
    stackedWidget.show();

    // Запуск приложения
    return app.exec();
}
