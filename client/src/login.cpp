#include "login.h"
#include "ui_login.h"
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm),
    socket(new QTcpSocket(this))
{
    ui->setupUi(this);

    // Подключение сигналов к слотам
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginForm::onLoginClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &LoginForm::onBackClicked);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::onLoginClicked() {
    QString login = ui->loginField->text();
    QString password = ui->passwordField->text();

    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поля не должны быть пустыми");
        return;
    }

    // Закрываем предыдущее соединение, если оно было установлено
    if (socket->state() == QTcpSocket::ConnectedState) {
        socket->disconnectFromHost();
        if (socket->state() == QTcpSocket::ConnectedState) {
            socket->waitForDisconnected();
        }
    }

    // Подключение к серверу перед новым запросом
    socket->connectToHost("127.0.0.1", 12345);
    if (!socket->waitForConnected(3000)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось подключиться к серверу");
        return;
    }

    // Отправляем запрос на сервер
    QString message = QString("auth&%1&%2").arg(login, password);
    qDebug() << "Отправляем запрос: " << message;

    socket->write(message.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(5000)) {
        QString response = socket->readAll();
        qDebug() << "Ответ от сервера: " << response;

        if (response.startsWith("auth+")) {
            QMessageBox::information(this, "Успех", "Успешная авторизация!");
            emit openMainMenu();  // Переход в главное меню после успешной авторизации
        } else {
            QMessageBox::warning(this, "Ошибка", "Неправильный логин или пароль");
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Нет ответа от сервера");
    }

    // Закрываем соединение после обработки
    socket->disconnectFromHost();
}

void LoginForm::onBackClicked() {
    emit backToMainMenu();
}
