#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QTcpSocket>  // Подключаем QTcpSocket для работы с сетью

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT  // Это обязательно для использования сигналов и слотов

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void backToMainMenu();  // Сигнал для возврата в главное меню
    void openMainMenu();    // Новый сигнал для перехода в главное меню после авторизации

private slots:
    void onLoginClicked();  // Слот для обработки нажатия на кнопку "Логин"
    void onBackClicked();   // Слот для обработки нажатия на кнопку "Назад"

private:
    Ui::LoginForm *ui;
    QTcpSocket *socket;  // Для подключения к серверу
};

#endif // LOGINFORM_H
