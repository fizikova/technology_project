#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include "controller.h"

class ServerInterface {
public:
    ServerInterface();  // Конструктор для инициализации
    void run();         // Метод для запуска сервера
private:
    void handleClient(int clientSocket);  // Метод для обработки клиентов
    Controller controller;  // Контроллер для обработки запросов
};

#endif // SERVER_INTERFACE_H
