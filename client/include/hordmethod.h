#ifndef HORDMETHODFORM_H
#define HORDMETHODFORM_H

#include <QWidget>
#include "ui_hord_method.h"  // Подключаем сгенерированный файл UI

namespace Ui {
class HordMethodForm;
}

class HordMethodForm : public QWidget
{
    Q_OBJECT

public:
    explicit HordMethodForm(QWidget *parent = nullptr);
    ~HordMethodForm();

signals:
    void backToMainMenu();

private slots:
    void onCalculateClicked();
    void onBackClicked();

private:
    Ui::HordMethodForm *ui;
};

#endif // HORDMETHODFORM_H
