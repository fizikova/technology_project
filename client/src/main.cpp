#include <QApplication>
#include <QStackedWidget>
#include "mainmenu.h"
#include "login.h"
#include "register.h"
#include "hordmethod.h"
#include "imageembed.h"
#include "functionmenu.h"
#include "vigenerecipher.h"
#include "sha384form.h"

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
    FunctionMenu *functionMenu = new FunctionMenu();
    VigenereCipherForm *vigenereCipherForm = new VigenereCipherForm();
    SHA384Form *sha384Form = new SHA384Form();

    // Добавляем окна в стек виджетов
    stackedWidget.addWidget(mainMenu);
    stackedWidget.addWidget(loginForm);
    stackedWidget.addWidget(registerForm);
    stackedWidget.addWidget(hordMethodForm);
    stackedWidget.addWidget(imageEmbedForm);
    stackedWidget.addWidget(functionMenu);
    stackedWidget.addWidget(vigenereCipherForm);
    stackedWidget.addWidget(sha384Form);

    // Переключение между окнами
    QObject::connect(mainMenu, &MainMenu::openLoginForm, [&]() {
        stackedWidget.setCurrentWidget(loginForm);
    });

    QObject::connect(mainMenu, &MainMenu::openRegisterForm, [&]() {
        stackedWidget.setCurrentWidget(registerForm);
    });

    QObject::connect(loginForm, &LoginForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    QObject::connect(loginForm, &LoginForm::openMainMenu, [&]() {
        stackedWidget.setCurrentWidget(functionMenu);  // Переход в меню функций после успешной авторизации
    });

    QObject::connect(functionMenu, &FunctionMenu::openHordMethod, [&]() {
        stackedWidget.setCurrentWidget(hordMethodForm);
    });

    QObject::connect(functionMenu, &FunctionMenu::openImageEmbed, [&]() {
        stackedWidget.setCurrentWidget(imageEmbedForm);
    });

    QObject::connect(functionMenu, &FunctionMenu::openVigenereCipher, [&]() {
        stackedWidget.setCurrentWidget(vigenereCipherForm);
    });

    QObject::connect(functionMenu, &FunctionMenu::openSha384, [&]() {
        stackedWidget.setCurrentWidget(sha384Form);
    });

    QObject::connect(functionMenu, &FunctionMenu::logout, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);  // Возвращение в главное меню при выходе
    });

    QObject::connect(registerForm, &RegisterForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(mainMenu);
    });

    QObject::connect(hordMethodForm, &HordMethodForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(functionMenu);  // Возврат в меню функций
    });

    QObject::connect(imageEmbedForm, &ImageEmbedForm::backToMainMenu, [&]() {
        stackedWidget.setCurrentWidget(functionMenu);  // Возврат в меню функций
    });

    QObject::connect(vigenereCipherForm, &VigenereCipherForm::backToFunctionMenu, [&]() {
        stackedWidget.setCurrentWidget(functionMenu);  // Возврат в меню функций
    });

    QObject::connect(sha384Form, &SHA384Form::backToFunctionMenu, [&]() {
        stackedWidget.setCurrentWidget(functionMenu);  // Возврат в меню функций
    });

    // Устанавливаем главное окно как начальное
    stackedWidget.setCurrentWidget(mainMenu);
    stackedWidget.resize(400, 300);  // Размер окна
    stackedWidget.show();

    // Запуск приложения
    return app.exec();
}
