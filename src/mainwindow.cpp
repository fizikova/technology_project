#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "taskwindow.h"
#include "registerwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    loginWindow(nullptr),
    taskWindow(nullptr),
    registerWindow(nullptr)
{
    ui->setupUi(this);
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &MainWindow::showLoginWindow);
    connect(ui->pushButtonRegister, &QPushButton::clicked, this, &MainWindow::showRegisterWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (loginWindow) {
        delete loginWindow;
    }
    if (taskWindow) {
        delete taskWindow;
    }
    if (registerWindow) {
        delete registerWindow;
    }
}

void MainWindow::showLoginWindow()
{
    if (!loginWindow) {
        loginWindow = new LoginWindow(this);
        connect(loginWindow, &LoginWindow::loginSuccessful, this, &MainWindow::showTaskWindow);
    }
    loginWindow->show();
    this->hide(); // Скрываем главное окно
}

void MainWindow::showTaskWindow()
{
    if (!taskWindow) {
        taskWindow = new TaskWindow();
        connect(taskWindow, &TaskWindow::logoutClicked, this, &MainWindow::show); // Показываем главное окно после закрытия окна задач
    }
    taskWindow->show();
    if (loginWindow) {
        loginWindow->close(); // Закрываем окно входа
    }
}

void MainWindow::showRegisterWindow()
{
    if (!registerWindow) {
        registerWindow = new RegisterWindow(this);
        connect(registerWindow, &RegisterWindow::registrationSuccessful, this, &MainWindow::show); // Показываем главное окно после успешной регистрации
        connect(registerWindow, &RegisterWindow::destroyed, this, &MainWindow::show); // Показываем главное окно после закрытия окна регистрации
    }
    registerWindow->show();
    this->hide(); // Скрываем главное окно
}
