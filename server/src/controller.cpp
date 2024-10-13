#include "controller.h"
#include "database.h"
#include <sstream>

std::string Controller::handleRequest(const std::string& request) {
    std::stringstream ss(request);
    std::string command;
    std::getline(ss, command, '&');

    if (command == "auth") {
        std::string login, password;
        std::getline(ss, login, '&');
        std::getline(ss, password, '&');
        return processAuth(login, password);
    } else if (command == "reg") {
        std::string login, password, email;
        std::getline(ss, login, '&');
        std::getline(ss, password, '&');
        std::getline(ss, email, '&');
        return processReg(login, password, email);
    }
    return "error";
}

std::string Controller::processAuth(const std::string& login, const std::string& password) {
    Database& db = Database::getInstance();
    if (db.authenticate(login, password)) {
        return "auth+&" + login;
    }
    return "auth-";
}

std::string Controller::processReg(const std::string& login, const std::string& password, const std::string& email) {
    Database& db = Database::getInstance();
    if (db.registerUser(login, password, email)) {
        return "reg+&" + login;
    }
    return "reg-";
}
