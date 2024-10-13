#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <unordered_map>

// Структура для хранения данных пользователя
struct User {
    std::string password;
    std::string email;
};

class Database {
public:
    // Получение единственного экземпляра базы данных
    static Database& getInstance();

    // Регистрация нового пользователя
    bool registerUser(const std::string& login, const std::string& password, const std::string& email);

    // Авторизация пользователя
    bool authenticate(const std::string& login, const std::string& password);

private:
    // Приватный конструктор для Singleton
    Database() {}

    // Приватный деструктор
    ~Database() {}

    // Приватный оператор копирования для предотвращения создания нескольких экземпляров
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    // Хранилище пользователей
    std::unordered_map<std::string, User> users;
};

#endif // DATABASE_H
