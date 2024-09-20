#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class LoginWindow;
class TaskWindow;
class RegisterWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showLoginWindow();
    void showTaskWindow();
    void showRegisterWindow();

private:
    Ui::MainWindow *ui;
    LoginWindow *loginWindow;
    TaskWindow *taskWindow;
    RegisterWindow *registerWindow;
};

#endif // MAINWINDOW_H
