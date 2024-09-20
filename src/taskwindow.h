#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QWidget>

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TaskWindow(QWidget *parent = nullptr);
    ~TaskWindow();

signals:
    void logoutClicked(); // Сигнал для выхода

private slots:
    void on_pushButtonSolveChord_clicked(); // Слот для кнопки "Solve Equation (Chord Method)"
    void on_pushButtonEmbedMessage_clicked(); // Слот для кнопки "Embed Message in Image"
    void on_pushButtonLogout_clicked(); // Слот для кнопки "Logout"

private:
    Ui::TaskWindow *ui;
    double chordMethod(double (*func)(double), double a, double b, double tol);
    void embedMessageInImage(const QString &inputImagePath, const QString &message, const QString &outputImagePath);
};

#endif // TASKWINDOW_H
