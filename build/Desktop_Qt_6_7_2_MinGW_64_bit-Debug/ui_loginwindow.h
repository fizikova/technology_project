/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonBack;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        lineEditUsername = new QLineEdit(LoginWindow);
        lineEditUsername->setObjectName("lineEditUsername");

        verticalLayout->addWidget(lineEditUsername);

        lineEditPassword = new QLineEdit(LoginWindow);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEditPassword);

        pushButtonLogin = new QPushButton(LoginWindow);
        pushButtonLogin->setObjectName("pushButtonLogin");

        verticalLayout->addWidget(pushButtonLogin);

        pushButtonBack = new QPushButton(LoginWindow);
        pushButtonBack->setObjectName("pushButtonBack");

        verticalLayout->addWidget(pushButtonBack);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("LoginWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
