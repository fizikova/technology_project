#include "database.h"

// Получение единственного экземпляра базы данных
Database& Database::getInstance() {
    static Database instance;
    return instance;
}

// Регистрация нового пользователя
bool Database::registerUser(const std::string& login, const std::string& password, const std::string& email) {
    if (users.find(login) != users.end()) {
        return false;  // Пользователь с таким логином уже существует
    }
    users[login] = {password, email};  // Добавляем пользователя в базу данных
    return true;
}

// Авторизация пользователя
bool Database::authenticate(const std::string& login, const std::string& password) {
    auto it = users.find(login);
    if (it != users.end() && it->second.password == password) {
        return true;  // Логин и пароль совпадают
    }
    return false;  // Неверный логин или пароль
}
