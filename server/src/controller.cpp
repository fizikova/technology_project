#include "controller.h"
#include "database.h"
#include <sstream>
#include <iostream>

std::string Controller::handleRequest(const std::string& request) {
    std::stringstream ss(request);
    std::string command;
    std::getline(ss, command, '&');

    if (command == "reg") {
        std::string login, password, email;
        std::getline(ss, login, '&');
        std::getline(ss, password, '&');
        std::getline(ss, email, '&');
        std::cout << "Processing registration for: " << login << std::endl;
        return processReg(login, password, email);
    } 
    else if (command == "auth") {
        std::string login, password;
        std::getline(ss, login, '&');
        std::getline(ss, password, '&');
        std::cout << "Processing authentication for: " << login << std::endl;
        return processAuth(login, password);
    }

    return "error: unknown command";
}

std::string Controller::processReg(const std::string& login, const std::string& password, const std::string& email) {
    Database& db = Database::getInstance();
    if (db.registerUser(login, password, email)) {
        std::cout << "Registration successful for: " << login << std::endl;
        return "reg+&success";
    }
    std::cout << "Registration failed for: " << login << std::endl;
    return "reg-&fail";
}

std::string Controller::processAuth(const std::string& login, const std::string& password) {
    Database& db = Database::getInstance();
    if (db.authenticate(login, password)) {
        std::cout << "Authentication successful for: " << login << std::endl;
        return "auth+&success";
    }
    std::cout << "Authentication failed for: " << login << std::endl;
    return "auth-&fail";
}
