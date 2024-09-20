#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void loginSuccessful(); // Сигнал для успешного входа

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonRegister_clicked();
    void on_pushButtonBack_clicked(); // Слот для кнопки "Back"

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
