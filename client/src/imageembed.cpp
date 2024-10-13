#include "imageembed.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include <bitset>

// Функция для внедрения сообщения в изображение
bool embedMessageInImage(const QString &imagePath, const QString &message, const QString &outputPath) {
    QImage image(imagePath);
    
    if (image.isNull()) {
        return false; // Ошибка при открытии изображения
    }

    QByteArray byteArray = message.toUtf8(); // Преобразуем сообщение в байтовый массив
    byteArray.append('\0'); // Добавляем завершающий символ для строки (конец сообщения)
    int messageLength = byteArray.size() * 8; // Общее количество бит в сообщении

    int pixelCount = image.width() * image.height(); // Количество пикселей в изображении
    if (messageLength > pixelCount * 3) { // Нужно 3 бита на каждый пиксель (по 1 биту на каждый цветовой канал)
        return false; // Сообщение слишком длинное для данного изображения
    }

    int bitIndex = 0; // Индекс текущего бита сообщения
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            if (bitIndex >= messageLength) {
                break;
            }

            QRgb pixel = image.pixel(x, y);

            // Получаем каждый цветовой канал (R, G, B)
            int red = qRed(pixel);
            int green = qGreen(pixel);
            int blue = qBlue(pixel);

            // Встраиваем бит сообщения в каждый цветовой канал, начиная с красного
            if (bitIndex < messageLength) {
                red = (red & ~1) | ((byteArray[bitIndex / 8] >> (7 - (bitIndex % 8))) & 1); // Внедрение в R
                bitIndex++;
            }
            if (bitIndex < messageLength) {
                green = (green & ~1) | ((byteArray[bitIndex / 8] >> (7 - (bitIndex % 8))) & 1); // Внедрение в G
                bitIndex++;
            }
            if (bitIndex < messageLength) {
                blue = (blue & ~1) | ((byteArray[bitIndex / 8] >> (7 - (bitIndex % 8))) & 1); // Внедрение в B
                bitIndex++;
            }

            // Устанавливаем изменённый пиксель обратно в изображение
            image.setPixel(x, y, qRgb(red, green, blue));
        }
    }

    // Сохраняем изменённое изображение
    return image.save(outputPath);
}

ImageEmbedForm::ImageEmbedForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageEmbedForm)
{
    ui->setupUi(this);
    connect(ui->browseButton, &QPushButton::clicked, this, &ImageEmbedForm::onBrowseClicked);
    connect(ui->embedButton, &QPushButton::clicked, this, &ImageEmbedForm::onEmbedClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &ImageEmbedForm::onBackClicked);
}

ImageEmbedForm::~ImageEmbedForm()
{
    delete ui;
}

void ImageEmbedForm::onBrowseClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выбрать изображение", "", "Images (*.png *.bmp)");
    if (!filePath.isEmpty()) {
        ui->imagePathField->setText(filePath);
    }
}

void ImageEmbedForm::onEmbedClicked()
{
    QString message = ui->messageField->text();
    QString imagePath = ui->imagePathField->text();

    if (message.isEmpty() || imagePath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля");
        return;
    }

    QString outputPath = QFileDialog::getSaveFileName(this, "Сохранить изображение", "", "Images (*.bmp)");
    if (outputPath.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите путь для сохранения");
        return;
    }

    // Внедрение сообщения в изображение
    if (embedMessageInImage(imagePath, message, outputPath)) {
        QMessageBox::information(this, "Успех", "Сообщение успешно внедрено в изображение");
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось внедрить сообщение");
    }
}

void ImageEmbedForm::onBackClicked()
{
    emit backToMainMenu();
}
