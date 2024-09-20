/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditEmail;
    QPushButton *pushButtonRegister;
    QPushButton *pushButtonBack;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegisterWindow);
        verticalLayout->setObjectName("verticalLayout");
        lineEditUsername = new QLineEdit(RegisterWindow);
        lineEditUsername->setObjectName("lineEditUsername");

        verticalLayout->addWidget(lineEditUsername);

        lineEditPassword = new QLineEdit(RegisterWindow);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEditPassword);

        lineEditEmail = new QLineEdit(RegisterWindow);
        lineEditEmail->setObjectName("lineEditEmail");

        verticalLayout->addWidget(lineEditEmail);

        pushButtonRegister = new QPushButton(RegisterWindow);
        pushButtonRegister->setObjectName("pushButtonRegister");

        verticalLayout->addWidget(pushButtonRegister);

        pushButtonBack = new QPushButton(RegisterWindow);
        pushButtonBack->setObjectName("pushButtonBack");

        verticalLayout->addWidget(pushButtonBack);


        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Username", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("RegisterWindow", "Email", nullptr));
        pushButtonRegister->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("RegisterWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
