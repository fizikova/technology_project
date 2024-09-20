#include "taskwindow.h"
#include "ui_taskwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <cmath>
#include <iostream>
#include <QDebug>
#include "chord.h"
#include "vigener.h"

TaskWindow::TaskWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWindow)
{
    ui->setupUi(this);
    qDebug() << "TaskWindow setupUi called";
    connect(ui->pushButtonSolveChord, &QPushButton::clicked, this, &TaskWindow::on_pushButtonSolveChord_clicked);
    connect(ui->pushButtonEmbedMessage, &QPushButton::clicked, this, &TaskWindow::on_pushButtonEmbedMessage_clicked);
    connect(ui->pushButtonLogout, &QPushButton::clicked, this, &TaskWindow::on_pushButtonLogout_clicked);
}

TaskWindow::~TaskWindow()
{
    delete ui;
    qDebug() << "TaskWindow destroyed";
}

void TaskWindow::on_pushButtonSolveChord_clicked()
{
    qDebug() << "Solve Chord button clicked";

    bool ok1, ok2, ok3;
    double a = QInputDialog::getDouble(this, "Input", "Enter a:", 0, -2147483647, 2147483647, 2, &ok1);
    double b = QInputDialog::getDouble(this, "Input", "Enter b:", 0, -2147483647, 2147483647, 2, &ok2);
    double tol = QInputDialog::getDouble(this, "Input", "Enter tolerance:", 0.001, 0, 2147483647, 3, &ok3);

    if (ok1 && ok2 && ok3) {
        double result = chord_method([](double x) { return std::cos(x) - x; }, a, b, tol);
        QMessageBox::information(this, "Result", QString("The root is: %1").arg(result));
    }
}

void TaskWindow::on_pushButtonEmbedMessage_clicked()
{
    qDebug() << "Embed Message button clicked";

    QString imagePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (imagePath.isEmpty()) {
        return;
    }

    bool ok;
    QString message = QInputDialog::getText(this, "Input Message", "Message:", QLineEdit::Normal, "", &ok);
    if (!ok || message.isEmpty()) {
        return;
    }

    QString outputPath = QFileDialog::getSaveFileName(this, "Save Image", "", "Images (*.png *.jpg *.bmp)");
    if (outputPath.isEmpty()) {
        return;
    }

    try {
        embedMessageInImage(imagePath, message, outputPath);
        QMessageBox::information(this, "Success", "Message embedded successfully!");
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void TaskWindow::on_pushButtonLogout_clicked()
{
    qDebug() << "Logout button clicked";
    emit logoutClicked(); // Испускаем сигнал для выхода
    this->close(); // Закрываем окно задач
}

void TaskWindow::embedMessageInImage(const QString &inputImagePath, const QString &message, const QString &outputImagePath)
{
    ::embedMessageInImage(inputImagePath.toStdString(), message.toStdString(), outputImagePath.toStdString());
}
