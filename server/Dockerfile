# Используем базовый образ с установленным компилятором g++
FROM gcc:latest

# Создаём рабочую директорию в контейнере
WORKDIR /usr/src/app

# Копируем все исходные файлы и заголовки в рабочую директорию
COPY . .

# Собираем серверное приложение, указывая путь к заголовочным файлам
RUN g++ -Iinclude -o server_app src/main.cpp src/server_interface.cpp src/controller.cpp src/database.cpp -lpthread

# Открываем порт, который будет слушать сервер
EXPOSE 12345

# Команда для запуска сервера
CMD ["./server_app"]
