#ifndef FUNCTIONMENU_H
#define FUNCTIONMENU_H

#include <QWidget>

namespace Ui {
class FunctionMenu;
}

class FunctionMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionMenu(QWidget *parent = nullptr);
    ~FunctionMenu();

signals:
    void openHordMethod();       // Уже существующий сигнал для метода хорд
    void openImageEmbed();       // Уже существующий сигнал для Image Embed
    void openVigenereCipher();   // Новый сигнал для окна шифра Виженера
    void openSha384();           // Новый сигнал для окна SHA-384
    void logout();               // Уже существующий сигнал для выхода

private slots:
    void onHordMethodClicked();  // Уже существующий слот для метода хорд
    void onImageEmbedClicked();  // Уже существующий слот для Image Embed
    void onVigenereCipherClicked(); // Новый слот для шифра Виженера
    void onSha384Clicked();      // Новый слот для SHA-384
    void onLogoutClicked();      // Уже существующий слот для выхода

private:
    Ui::FunctionMenu *ui;
};

#endif // FUNCTIONMENU_H
