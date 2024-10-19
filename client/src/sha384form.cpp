#include "sha384form.h"
#include "ui_sha384form.h"
#include <QCryptographicHash>

SHA384Form::SHA384Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SHA384Form)
{
    ui->setupUi(this);

    // Подключение кнопок к слотам
    connect(ui->hashButton, &QPushButton::clicked, this, &SHA384Form::onHashClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &SHA384Form::onBackClicked);
}

SHA384Form::~SHA384Form()
{
    delete ui;
}

QString SHA384Form::hashText(const QString &text) {
    QByteArray byteArray = text.toUtf8();  // Преобразование текста в байтовый массив
    QByteArray hashArray = QCryptographicHash::hash(byteArray, QCryptographicHash::Sha384);
    return hashArray.toHex();  // Возвращает хеш в шестнадцатеричном формате
}

void SHA384Form::onHashClicked() {
    QString text = ui->textField->text();  // Получаем текст из текстового поля
    ui->resultField->setText(hashText(text));  // Устанавливаем хеш в поле результата
}

void SHA384Form::onBackClicked() {
    emit backToFunctionMenu();  // Вызываем сигнал при нажатии кнопки "Назад"
}
