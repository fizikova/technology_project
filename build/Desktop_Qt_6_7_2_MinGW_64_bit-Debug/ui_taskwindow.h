/********************************************************************************
** Form generated from reading UI file 'taskwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWINDOW_H
#define UI_TASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonSolveChord;
    QPushButton *pushButtonEmbedMessage;
    QPushButton *pushButtonLogout;

    void setupUi(QWidget *TaskWindow)
    {
        if (TaskWindow->objectName().isEmpty())
            TaskWindow->setObjectName("TaskWindow");
        TaskWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(TaskWindow);
        verticalLayout->setObjectName("verticalLayout");
        pushButtonSolveChord = new QPushButton(TaskWindow);
        pushButtonSolveChord->setObjectName("pushButtonSolveChord");

        verticalLayout->addWidget(pushButtonSolveChord);

        pushButtonEmbedMessage = new QPushButton(TaskWindow);
        pushButtonEmbedMessage->setObjectName("pushButtonEmbedMessage");

        verticalLayout->addWidget(pushButtonEmbedMessage);

        pushButtonLogout = new QPushButton(TaskWindow);
        pushButtonLogout->setObjectName("pushButtonLogout");

        verticalLayout->addWidget(pushButtonLogout);


        retranslateUi(TaskWindow);

        QMetaObject::connectSlotsByName(TaskWindow);
    } // setupUi

    void retranslateUi(QWidget *TaskWindow)
    {
        TaskWindow->setWindowTitle(QCoreApplication::translate("TaskWindow", "TaskWindow", nullptr));
        pushButtonSolveChord->setText(QCoreApplication::translate("TaskWindow", "Solve Equation (Chord Method)", nullptr));
        pushButtonEmbedMessage->setText(QCoreApplication::translate("TaskWindow", "Embed Message in Image", nullptr));
        pushButtonLogout->setText(QCoreApplication::translate("TaskWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWindow: public Ui_TaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
