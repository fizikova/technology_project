/********************************************************************************
** Form generated from reading UI file 'hord_method.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HORD_METHOD_H
#define UI_HORD_METHOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HordMethodForm
{
public:
    QLabel *label_a;
    QLineEdit *field_a;
    QLabel *label_b;
    QLineEdit *field_b;
    QLabel *label_tolerance;
    QLineEdit *field_tolerance;
    QPushButton *calculateButton;
    QPushButton *backButton;

    void setupUi(QWidget *HordMethodForm)
    {
        if (HordMethodForm->objectName().isEmpty())
            HordMethodForm->setObjectName("HordMethodForm");
        HordMethodForm->resize(400, 300);
        label_a = new QLabel(HordMethodForm);
        label_a->setObjectName("label_a");
        label_a->setGeometry(QRect(50, 50, 30, 30));
        field_a = new QLineEdit(HordMethodForm);
        field_a->setObjectName("field_a");
        field_a->setGeometry(QRect(80, 50, 200, 30));
        label_b = new QLabel(HordMethodForm);
        label_b->setObjectName("label_b");
        label_b->setGeometry(QRect(50, 100, 30, 30));
        field_b = new QLineEdit(HordMethodForm);
        field_b->setObjectName("field_b");
        field_b->setGeometry(QRect(80, 100, 200, 30));
        label_tolerance = new QLabel(HordMethodForm);
        label_tolerance->setObjectName("label_tolerance");
        label_tolerance->setGeometry(QRect(50, 150, 60, 30));
        field_tolerance = new QLineEdit(HordMethodForm);
        field_tolerance->setObjectName("field_tolerance");
        field_tolerance->setGeometry(QRect(120, 150, 160, 30));
        calculateButton = new QPushButton(HordMethodForm);
        calculateButton->setObjectName("calculateButton");
        calculateButton->setGeometry(QRect(80, 200, 100, 30));
        backButton = new QPushButton(HordMethodForm);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(200, 200, 100, 30));

        retranslateUi(HordMethodForm);

        QMetaObject::connectSlotsByName(HordMethodForm);
    } // setupUi

    void retranslateUi(QWidget *HordMethodForm)
    {
        HordMethodForm->setWindowTitle(QCoreApplication::translate("HordMethodForm", "\320\234\320\265\321\202\320\276\320\264 \321\205\320\276\321\200\320\264", nullptr));
        label_a->setText(QCoreApplication::translate("HordMethodForm", "a:", nullptr));
        label_b->setText(QCoreApplication::translate("HordMethodForm", "b:", nullptr));
        label_tolerance->setText(QCoreApplication::translate("HordMethodForm", "\320\224\320\276\320\277\321\203\321\201\320\272:", nullptr));
        calculateButton->setText(QCoreApplication::translate("HordMethodForm", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("HordMethodForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HordMethodForm: public Ui_HordMethodForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HORD_METHOD_H
