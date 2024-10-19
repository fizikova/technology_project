#ifndef DATABASE_H
#define DATABASE_H

#include <string>   // Для использования std::string
#include <sqlite3.h> // Для работы с SQLite

class Database {
public:
    static Database& getInstance();
    bool registerUser(const std::string& login, const std::string& password, const std::string& email);
    bool authenticate(const std::string& login, const std::string& password);

private:
    Database();
    ~Database();
    sqlite3* db;  // Переменная для подключения к базе данных
};

#endif
