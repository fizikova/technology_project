#ifndef SHA384FORM_H
#define SHA384FORM_H

#include <QWidget>

namespace Ui {
class SHA384Form;
}

class SHA384Form : public QWidget
{
    Q_OBJECT

public:
    explicit SHA384Form(QWidget *parent = nullptr);
    ~SHA384Form();
    QString hashText(const QString &text);  // Функция хэширования текста

private slots:
    void onHashClicked();
    void onBackClicked();

signals:
    void backToFunctionMenu();  // Сигнал для возврата в меню

private:
    Ui::SHA384Form *ui;
};

#endif // SHA384FORM_H
