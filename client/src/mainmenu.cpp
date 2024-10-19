#include "mainmenu.h"
#include "ui_main_menu.h"
#include <QMessageBox>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainMenu::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &MainMenu::onRegisterClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainMenu::close);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::onLoginClicked()
{
    emit openLoginForm();
}

void MainMenu::onRegisterClicked()
{
    emit openRegisterForm();
}
