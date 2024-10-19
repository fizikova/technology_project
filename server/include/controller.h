#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Controller {
public:
    // Обрабатывает запросы от клиента
    std::string handleRequest(const std::string& request);

private:
    // Методы для авторизации и регистрации
    std::string processAuth(const std::string& login, const std::string& password);
    std::string processReg(const std::string& login, const std::string& password, const std::string& email);
};

#endif // CONTROLLER_H
