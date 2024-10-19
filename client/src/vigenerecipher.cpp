#include "vigenerecipher.h"
#include "ui_vigenerecipher.h"

VigenereCipherForm::VigenereCipherForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VigenereCipherForm)
{
    ui->setupUi(this);

    // Подключение кнопок к слотам
    connect(ui->encryptButton, &QPushButton::clicked, this, &VigenereCipherForm::onEncryptClicked);
    connect(ui->decryptButton, &QPushButton::clicked, this, &VigenereCipherForm::onDecryptClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &VigenereCipherForm::onBackClicked);  // Кнопка "Назад"
}

VigenereCipherForm::~VigenereCipherForm()
{
    delete ui;
}

QString VigenereCipherForm::encrypt(const QString &text, const QString &key) {
    QString result;
    for (int i = 0; i < text.length(); ++i) {
        result.append(QChar(((text[i].unicode() - 'A' + key[i % key.length()].unicode() - 'A') % 26) + 'A'));
    }
    return result;
}

QString VigenereCipherForm::decrypt(const QString &text, const QString &key) {
    QString result;
    for (int i = 0; i < text.length(); ++i) {
        result.append(QChar(((text[i].unicode() - key[i % key.length()].unicode() + 26) % 26) + 'A'));
    }
    return result;
}

void VigenereCipherForm::onEncryptClicked() {
    QString text = ui->textField->text().toUpper();
    QString key = ui->keyField->text().toUpper();
    ui->resultField->setText(encrypt(text, key));
}

void VigenereCipherForm::onDecryptClicked() {
    QString text = ui->textField->text().toUpper();
    QString key = ui->keyField->text().toUpper();
    ui->resultField->setText(decrypt(text, key));
}

void VigenereCipherForm::onBackClicked() {
    emit backToFunctionMenu();  // Возврат в меню функций
}
