/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterForm
{
public:
    QLabel *loginLabel;
    QLineEdit *loginField;
    QLabel *passwordLabel;
    QLineEdit *passwordField;
    QLabel *emailLabel;
    QLineEdit *emailField;
    QPushButton *registerButton;
    QPushButton *backButton;

    void setupUi(QWidget *RegisterForm)
    {
        if (RegisterForm->objectName().isEmpty())
            RegisterForm->setObjectName("RegisterForm");
        RegisterForm->resize(400, 300);
        loginLabel = new QLabel(RegisterForm);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(50, 50, 60, 30));
        loginField = new QLineEdit(RegisterForm);
        loginField->setObjectName("loginField");
        loginField->setGeometry(QRect(120, 50, 200, 30));
        passwordLabel = new QLabel(RegisterForm);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(50, 100, 60, 30));
        passwordField = new QLineEdit(RegisterForm);
        passwordField->setObjectName("passwordField");
        passwordField->setGeometry(QRect(120, 100, 200, 30));
        passwordField->setEchoMode(QLineEdit::Password);
        emailLabel = new QLabel(RegisterForm);
        emailLabel->setObjectName("emailLabel");
        emailLabel->setGeometry(QRect(50, 150, 60, 30));
        emailField = new QLineEdit(RegisterForm);
        emailField->setObjectName("emailField");
        emailField->setGeometry(QRect(120, 150, 200, 30));
        registerButton = new QPushButton(RegisterForm);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(120, 200, 100, 30));
        backButton = new QPushButton(RegisterForm);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(230, 200, 100, 30));

        retranslateUi(RegisterForm);

        QMetaObject::connectSlotsByName(RegisterForm);
    } // setupUi

    void retranslateUi(QWidget *RegisterForm)
    {
        RegisterForm->setWindowTitle(QCoreApplication::translate("RegisterForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        loginLabel->setText(QCoreApplication::translate("RegisterForm", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegisterForm", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegisterForm", "Email:", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterForm", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        backButton->setText(QCoreApplication::translate("RegisterForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterForm: public Ui_RegisterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
