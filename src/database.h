#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QVariant>

class Database {
public:
    static Database& getInstance();
    bool open();
    void close();
    bool executeQuery(const QString &queryStr);
    QSqlQuery executeSelectQuery(const QString &queryStr);

private:
    Database();
    ~Database();
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;

    QSqlDatabase db;
};

#endif // DATABASE_H
