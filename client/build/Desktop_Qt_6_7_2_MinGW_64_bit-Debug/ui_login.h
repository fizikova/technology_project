/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *loginLabel;
    QLineEdit *loginField;
    QLabel *passwordLabel;
    QLineEdit *passwordField;
    QPushButton *loginButton;
    QPushButton *backButton;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(400, 300);
        loginLabel = new QLabel(LoginForm);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(50, 50, 60, 30));
        loginField = new QLineEdit(LoginForm);
        loginField->setObjectName("loginField");
        loginField->setGeometry(QRect(120, 50, 200, 30));
        passwordLabel = new QLabel(LoginForm);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(50, 100, 60, 30));
        passwordField = new QLineEdit(LoginForm);
        passwordField->setObjectName("passwordField");
        passwordField->setGeometry(QRect(120, 100, 200, 30));
        passwordField->setEchoMode(QLineEdit::Password);
        loginButton = new QPushButton(LoginForm);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(120, 150, 100, 30));
        backButton = new QPushButton(LoginForm);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(230, 150, 100, 30));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "\320\222\321\205\320\276\320\264", nullptr));
        loginLabel->setText(QCoreApplication::translate("LoginForm", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginForm", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginForm", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        backButton->setText(QCoreApplication::translate("LoginForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
