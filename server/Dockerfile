# Используем базовый образ Ubuntu
FROM ubuntu:latest

# Обновляем пакеты и устанавливаем зависимости
RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    make \
    sqlite3 \
    libsqlite3-dev \
    apt-utils

# Создание рабочей директории
WORKDIR /usr/src/app

# Копируем все файлы проекта в контейнер
COPY . .

# Компилируем проект, указав директорию с заголовками (-Iinclude)
RUN g++ -o server src/*.cpp -Iinclude -lpthread -lsqlite3

# Открываем порт для сервера
EXPOSE 12345

# Команда для запуска приложения
CMD ["./server"]
