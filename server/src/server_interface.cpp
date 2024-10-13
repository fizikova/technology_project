#include "server_interface.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

ServerInterface::ServerInterface() {
    // Здесь можно инициализировать серверные параметры
}

void ServerInterface::run() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Создание сокета
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Настройка сокета
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(12345);

    // Привязка сокета к порту
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Ожидание подключений
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "Сервер запущен и ждёт подключений на порту 12345" << std::endl;

    // Основной цикл обработки клиентов
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        std::cout << "Клиент подключен!" << std::endl;

        // Обработка клиента
        handleClient(new_socket);

        // Закрытие соединения
        close(new_socket);
    }
}

void ServerInterface::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    int valread = read(clientSocket, buffer, 1024);
    std::string request(buffer);

    std::cout << "Запрос от клиента: " << request << std::endl;

    // Обработка запроса
    std::string response = controller.handleRequest(request);

    // Отправляем ответ клиенту
    send(clientSocket, response.c_str(), response.length(), 0);
    std::cout << "Отправлен ответ: " << response << std::endl;
}
