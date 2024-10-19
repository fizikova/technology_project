#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <QTcpSocket>  // Подключаем QTcpSocket

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

signals:
    void backToMainMenu();

private slots:
    void onRegisterClicked();
    void onBackClicked();

private:
    Ui::RegisterForm *ui;
    QTcpSocket *socket;  // Добавляем поле для сокета
};

#endif // REGISTERFORM_H
