#include "database.h"
#include <sqlite3.h>
#include <string>
#include <iostream>

// Инициализация базы данных
Database::Database() {
    if (sqlite3_open("user_database.db", &db) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Database opened successfully" << std::endl;
    }

    // Создание таблицы пользователей, если её нет
    const char* create_table_sql = "CREATE TABLE IF NOT EXISTS users (login TEXT PRIMARY KEY, password TEXT NOT NULL, email TEXT)";
    if (sqlite3_exec(db, create_table_sql, 0, 0, 0) != SQLITE_OK) {
        std::cerr << "Failed to create table: " << sqlite3_errmsg(db) << std::endl;
    }
}

// Закрытие базы данных
Database::~Database() {
    sqlite3_close(db);
}

// Получение единственного экземпляра базы данных (синглтон)
Database& Database::getInstance() {
    static Database instance;  // Единственный экземпляр класса
    return instance;
}

// Регистрация нового пользователя
bool Database::registerUser(const std::string& login, const std::string& password, const std::string& email) {
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO users (login, password, email) VALUES (?, ?, ?)";
    sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return true;
    } else {
        std::cerr << "SQLite error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;  // Пользователь уже существует или произошла другая ошибка
    }
}

// Авторизация пользователя
bool Database::authenticate(const std::string& login, const std::string& password) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT password FROM users WHERE login = ?";
    sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC);
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* db_password = (const char*)sqlite3_column_text(stmt, 0);
        if (password == db_password) {
            sqlite3_finalize(stmt);
            return true;  // Успешная авторизация
        }
    }
    sqlite3_finalize(stmt);
    return false;  // Неверный логин или пароль
}
