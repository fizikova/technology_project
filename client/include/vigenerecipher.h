#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include <QWidget>

namespace Ui {
class VigenereCipherForm;
}

class VigenereCipherForm : public QWidget
{
    Q_OBJECT

public:
    explicit VigenereCipherForm(QWidget *parent = nullptr);
    ~VigenereCipherForm();

    // Изменить доступ к методам на public
    QString encrypt(const QString &text, const QString &key);
    QString decrypt(const QString &text, const QString &key);

signals:
    void backToFunctionMenu();  // Сигнал для возврата в меню функций

private slots:
    void onEncryptClicked();
    void onDecryptClicked();
    void onBackClicked();  // Слот для кнопки "Назад"

private:
    Ui::VigenereCipherForm *ui;
};

#endif // VIGENERECIPHER_H
