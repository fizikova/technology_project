#ifndef IMAGEEMBEDFORM_H
#define IMAGEEMBEDFORM_H

#include <QWidget>
#include "ui_image_embed.h"  // Подключаем сгенерированный файл UI

namespace Ui {
class ImageEmbedForm;
}

class ImageEmbedForm : public QWidget
{
    Q_OBJECT

public:
    explicit ImageEmbedForm(QWidget *parent = nullptr);
    ~ImageEmbedForm();

signals:
    void backToMainMenu();

private slots:
    void onBrowseClicked();
    void onEmbedClicked();
    void onBackClicked();

private:
    Ui::ImageEmbedForm *ui;
};

#endif // IMAGEEMBEDFORM_H
