/********************************************************************************
** Form generated from reading UI file 'sha384form.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHA384FORM_H
#define UI_SHA384FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SHA384Form
{
public:
    QLabel *labelText;
    QLineEdit *textField;
    QPushButton *hashButton;
    QLabel *labelResult;
    QLineEdit *resultField;
    QPushButton *backButton;

    void setupUi(QWidget *SHA384Form)
    {
        if (SHA384Form->objectName().isEmpty())
            SHA384Form->setObjectName("SHA384Form");
        SHA384Form->resize(400, 300);
        labelText = new QLabel(SHA384Form);
        labelText->setObjectName("labelText");
        labelText->setGeometry(QRect(50, 50, 60, 30));
        textField = new QLineEdit(SHA384Form);
        textField->setObjectName("textField");
        textField->setGeometry(QRect(120, 50, 200, 30));
        hashButton = new QPushButton(SHA384Form);
        hashButton->setObjectName("hashButton");
        hashButton->setGeometry(QRect(150, 100, 100, 30));
        labelResult = new QLabel(SHA384Form);
        labelResult->setObjectName("labelResult");
        labelResult->setGeometry(QRect(50, 150, 60, 30));
        resultField = new QLineEdit(SHA384Form);
        resultField->setObjectName("resultField");
        resultField->setReadOnly(true);
        resultField->setGeometry(QRect(120, 150, 200, 30));
        backButton = new QPushButton(SHA384Form);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(150, 250, 100, 30));

        retranslateUi(SHA384Form);

        QMetaObject::connectSlotsByName(SHA384Form);
    } // setupUi

    void retranslateUi(QWidget *SHA384Form)
    {
        SHA384Form->setWindowTitle(QCoreApplication::translate("SHA384Form", "SHA-384 \320\245\320\265\321\210\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        labelText->setText(QCoreApplication::translate("SHA384Form", "\320\242\320\265\320\272\321\201\321\202:", nullptr));
        hashButton->setText(QCoreApplication::translate("SHA384Form", "\320\245\320\265\321\210\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        labelResult->setText(QCoreApplication::translate("SHA384Form", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202:", nullptr));
        backButton->setText(QCoreApplication::translate("SHA384Form", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SHA384Form: public Ui_SHA384Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHA384FORM_H
