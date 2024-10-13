#include "hordmethod.h"
#include <QMessageBox>
#include <cmath>

// Функция, для которой мы ищем корень (пример)
double f(double x) {
    return pow(x, 3) - 4 * x - 9; // Пример: f(x) = x^3 - 4x - 9
}

// Метод хорд
double chordMethod(double a, double b, double tolerance) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) {
        throw std::invalid_argument("Функция должна иметь разные знаки на концах отрезка.");
    }

    double x_prev = a;
    double x = b;

    while (std::abs(x - x_prev) > tolerance) {
        x_prev = x;
        x = x - (f(x) * (x - a)) / (f(x) - fa);
    }

    return x;
}

HordMethodForm::HordMethodForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HordMethodForm)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &HordMethodForm::onCalculateClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &HordMethodForm::onBackClicked);
}

HordMethodForm::~HordMethodForm()
{
    delete ui;
}

void HordMethodForm::onCalculateClicked()
{
    QString a_str = ui->field_a->text();
    QString b_str = ui->field_b->text();
    QString tolerance_str = ui->field_tolerance->text();

    if (a_str.isEmpty() || b_str.isEmpty() || tolerance_str.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        return;
    }

    bool ok1, ok2, ok3;
    double a = a_str.toDouble(&ok1);
    double b = b_str.toDouble(&ok2);
    double tolerance = tolerance_str.toDouble(&ok3);

    if (!ok1 || !ok2 || !ok3) {
        QMessageBox::warning(this, "Ошибка", "Введены некорректные значения.");
        return;
    }

    if (tolerance <= 0) {
        QMessageBox::warning(this, "Ошибка", "Допуск должен быть положительным числом.");
        return;
    }

    try {
        double root = chordMethod(a, b, tolerance);
        QMessageBox::information(this, "Результат", QString("Корень уравнения: %1").arg(root));
    } catch (std::exception& e) {
        QMessageBox::warning(this, "Ошибка", e.what());
    }
}

void HordMethodForm::onBackClicked()
{
    emit backToMainMenu();
}
