#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

signals:
    void openLoginForm();
    void openRegisterForm();

private slots:
    void onLoginClicked();
    void onRegisterClicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
