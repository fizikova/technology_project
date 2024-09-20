#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "database.h"
#include "registerwindow.h"
#include <QMessageBox>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonBack, &QPushButton::clicked, this, &LoginWindow::on_pushButtonBack_clicked); // Подключаем кнопку "Back" к слоту
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked() {
    qDebug() << "Login button clicked";
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Please fill in all fields");
        return;
    }

    Database &db = Database::getInstance();
    db.open();
    QString queryStr = QString("SELECT * FROM users WHERE username='%1' AND password='%2'")
                           .arg(username).arg(password);
    QSqlQuery query = db.executeSelectQuery(queryStr);

    if (query.next()) {
        QMessageBox::information(this, "Login", "Login successful");
        emit loginSuccessful(); // Испускаем сигнал
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password");
    }
    db.close();
}

void LoginWindow::on_pushButtonRegister_clicked() {
    RegisterWindow registerWindow(this);
    connect(&registerWindow, &RegisterWindow::destroyed, this->parentWidget(), &QWidget::show); // Показываем главное окно после закрытия окна регистрации
    this->hide(); // Скрываем окно входа
    registerWindow.exec();
}

void LoginWindow::on_pushButtonBack_clicked() {
    this->close(); // Закрываем окно входа при нажатии кнопки "Back"
    QWidget *parent = this->parentWidget();
    if (parent) {
        parent->show(); // Показываем родительское окно
    }
}
