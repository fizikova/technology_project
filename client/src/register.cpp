#include "register.h"
#include "ui_register.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

RegisterForm::RegisterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterForm),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    // Подключение сигналов к слотам
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterForm::onRegisterClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &RegisterForm::onBackClicked);

    // Подключение к серверу
    socket->connectToHost("127.0.0.1", 12345);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось подключиться к серверу");
    }
}

RegisterForm::~RegisterForm()
{
    delete ui;
}

void RegisterForm::onRegisterClicked() {
    QString login = ui->loginField->text();
    QString password = ui->passwordField->text();
    QString email = ui->emailField->text();

    if (login.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        return;
    }

    // Формируем сообщение для регистрации
    QString message = QString("reg&%1&%2&%3").arg(login, password, email);
    qDebug() << "Отправляем запрос: " << message;

    // Отправляем запрос на сервер
    socket->write(message.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(5000)) {
        QString response = socket->readAll();
        qDebug() << "Ответ от сервера: " << response;

        if (response.startsWith("reg+")) {
            QMessageBox::information(this, "Успех", "Регистрация прошла успешно!");
        } else {
            QMessageBox::warning(this, "Ошибка", "Регистрация не удалась");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Нет ответа от сервера");
    }
}

void RegisterForm::onBackClicked() {
    emit backToMainMenu();  // Возвращаемся в главное меню через сигнал
}
