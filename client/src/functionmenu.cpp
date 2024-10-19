#include "functionmenu.h"
#include "ui_functionmenu.h"

FunctionMenu::FunctionMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionMenu)
{
    ui->setupUi(this);

    // Подключение кнопок к слотам
    connect(ui->hordMethodButton, &QPushButton::clicked, this, &FunctionMenu::onHordMethodClicked);
    connect(ui->imageEmbedButton, &QPushButton::clicked, this, &FunctionMenu::onImageEmbedClicked);
    connect(ui->vigenereCipherButton, &QPushButton::clicked, this, &FunctionMenu::onVigenereCipherClicked); // Новый слот для шифра Виженера
    connect(ui->sha384Button, &QPushButton::clicked, this, &FunctionMenu::onSha384Clicked); // Новый слот для SHA-384
    connect(ui->logoutButton, &QPushButton::clicked, this, &FunctionMenu::onLogoutClicked);
}

FunctionMenu::~FunctionMenu()
{
    delete ui;
}

void FunctionMenu::onHordMethodClicked() {
    emit openHordMethod();
}

void FunctionMenu::onImageEmbedClicked() {
    emit openImageEmbed();
}

void FunctionMenu::onVigenereCipherClicked() {
    emit openVigenereCipher();  // Новый сигнал для открытия шифра Виженера
}

void FunctionMenu::onSha384Clicked() {
    emit openSha384();  // Новый сигнал для открытия SHA-384
}

void FunctionMenu::onLogoutClicked() {
    emit logout();
}
