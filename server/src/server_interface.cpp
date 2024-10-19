#include "server_interface.h"
#include "controller.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

ServerInterface::ServerInterface() {
    // Инициализация параметров сервера
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

    // Начало прослушивания
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (true) {
        std::cout << "Waiting for a connection..." << std::endl;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[1024] = {0};
        int valread = read(new_socket, buffer, 1024);
        std::string request(buffer);

        // Логирование полученного запроса
        std::cout << "Received request: " << request << std::endl;

        // Обработка запроса через контроллер
        Controller controller;
        std::string response = controller.handleRequest(request);

        // Отправка ответа клиенту
        send(new_socket, response.c_str(), response.size(), 0);

        // Закрытие сокета после обработки каждого запроса
        close(new_socket);
    }
}
