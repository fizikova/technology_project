/********************************************************************************
** Form generated from reading UI file 'image_embed.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE_EMBED_H
#define UI_IMAGE_EMBED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageEmbedForm
{
public:
    QLabel *label_message;
    QLineEdit *messageField;
    QLabel *label_image;
    QLineEdit *imagePathField;
    QPushButton *browseButton;
    QPushButton *embedButton;
    QPushButton *backButton;

    void setupUi(QWidget *ImageEmbedForm)
    {
        if (ImageEmbedForm->objectName().isEmpty())
            ImageEmbedForm->setObjectName("ImageEmbedForm");
        ImageEmbedForm->resize(400, 300);
        label_message = new QLabel(ImageEmbedForm);
        label_message->setObjectName("label_message");
        label_message->setGeometry(QRect(50, 50, 80, 30));
        messageField = new QLineEdit(ImageEmbedForm);
        messageField->setObjectName("messageField");
        messageField->setGeometry(QRect(130, 50, 200, 30));
        label_image = new QLabel(ImageEmbedForm);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(50, 100, 80, 30));
        imagePathField = new QLineEdit(ImageEmbedForm);
        imagePathField->setObjectName("imagePathField");
        imagePathField->setGeometry(QRect(130, 100, 200, 30));
        browseButton = new QPushButton(ImageEmbedForm);
        browseButton->setObjectName("browseButton");
        browseButton->setGeometry(QRect(340, 100, 50, 30));
        embedButton = new QPushButton(ImageEmbedForm);
        embedButton->setObjectName("embedButton");
        embedButton->setGeometry(QRect(130, 150, 100, 30));
        backButton = new QPushButton(ImageEmbedForm);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(250, 150, 100, 30));

        retranslateUi(ImageEmbedForm);

        QMetaObject::connectSlotsByName(ImageEmbedForm);
    } // setupUi

    void retranslateUi(QWidget *ImageEmbedForm)
    {
        ImageEmbedForm->setWindowTitle(QCoreApplication::translate("ImageEmbedForm", "\320\222\320\275\320\265\320\264\321\200\320\265\320\275\320\270\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217 \320\262 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        label_message->setText(QCoreApplication::translate("ImageEmbedForm", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265:", nullptr));
        label_image->setText(QCoreApplication::translate("ImageEmbedForm", "\320\232\320\260\321\200\321\202\320\270\320\275\320\272\320\260:", nullptr));
        browseButton->setText(QCoreApplication::translate("ImageEmbedForm", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        embedButton->setText(QCoreApplication::translate("ImageEmbedForm", "\320\222\320\275\320\265\320\264\321\200\320\270\321\202\321\214", nullptr));
        backButton->setText(QCoreApplication::translate("ImageEmbedForm", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageEmbedForm: public Ui_ImageEmbedForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE_EMBED_H
