#include "vigener.h"
#include <QImage>
#include <stdexcept>
#include <vector>

void embedMessageInImage(const std::string &imagePath, const std::string &message, const std::string &outputPath) {
    QImage image(QString::fromStdString(imagePath));
    if (image.isNull()) {
        throw std::runtime_error("Could not open or find the image");
    }

    std::vector<uchar> message_bytes(message.begin(), message.end());
    message_bytes.push_back('\0'); // Null-terminate the message

    auto message_bits = message_bytes.size() * 8;
    auto image_pixels = static_cast<std::vector<uchar>::size_type>(image.width() * image.height() * 3);

    if (message_bits > image_pixels) {
        throw std::runtime_error("Message is too large to embed in the image");
    }

    std::vector<uchar>::size_type bit_idx = 0;
    for (int row = 0; row < image.height(); ++row) {
        for (int col = 0; col < image.width(); ++col) {
            QRgb pixel = image.pixel(col, row);
            for (int color = 0; color < 3; ++color) {
                if (bit_idx < message_bits) {
                    uchar color_value;
                    switch (color) {
                    case 0:
                        color_value = qRed(pixel);
                        break;
                    case 1:
                        color_value = qGreen(pixel);
                        break;
                    case 2:
                        color_value = qBlue(pixel);
                        break;
                    }
                    color_value = (color_value & 0xFE) | ((message_bytes[bit_idx / 8] >> (bit_idx % 8)) & 0x01);
                    pixel = qRgb((color == 0) ? color_value : qRed(pixel),
                                 (color == 1) ? color_value : qGreen(pixel),
                                 (color == 2) ? color_value : qBlue(pixel));
                    ++bit_idx;
                }
            }
            image.setPixel(col, row, pixel);
        }
    }

    if (!image.save(QString::fromStdString(outputPath))) {
        throw std::runtime_error("Could not save the image");
    }
}
