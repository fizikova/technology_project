/********************************************************************************
** Form generated from reading UI file 'main_menu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *exitButton;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(400, 300);
        loginButton = new QPushButton(MainMenu);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(150, 50, 100, 30));
        registerButton = new QPushButton(MainMenu);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(150, 100, 100, 30));
        exitButton = new QPushButton(MainMenu);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(150, 150, 100, 30));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        loginButton->setText(QCoreApplication::translate("MainMenu", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        registerButton->setText(QCoreApplication::translate("MainMenu", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        exitButton->setText(QCoreApplication::translate("MainMenu", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
