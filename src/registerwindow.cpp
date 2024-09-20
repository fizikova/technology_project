#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "database.h"
#include <QMessageBox>
#include <QDebug>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonBack, &QPushButton::clicked, this, &RegisterWindow::on_pushButtonBack_clicked); // Подключаем кнопку "Back" к слоту
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButtonRegister_clicked() {
    qDebug() << "Register button clicked";
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Registration", "Please fill in all fields");
        return;
    }

    Database &db = Database::getInstance();
    db.open();
    QString queryStr = QString("INSERT INTO users (username, password) VALUES ('%1', '%2')")
                           .arg(username).arg(password);
    if (db.executeQuery(queryStr)) {
        QMessageBox::information(this, "Registration", "User registered successfully");
        emit registrationSuccessful(); // Испускаем сигнал
        this->close(); // Закрываем окно регистрации после успешной регистрации
    } else {
        QMessageBox::warning(this, "Registration", "Failed to register user");
    }
    db.close();
}

void RegisterWindow::on_pushButtonBack_clicked() {
    this->close(); // Закрываем окно регистрации при нажатии кнопки "Back"
    QWidget *parent = this->parentWidget();
    if (parent) {
        parent->show(); // Показываем родительское окно
    }
}
