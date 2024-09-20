#include "database.h"
#include <QDebug>

Database::Database() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("app_database.sqlite");
}

Database::~Database() {
    if (db.isOpen()) {
        db.close();
    }
}

Database& Database::getInstance() {
    static Database instance;
    return instance;
}

bool Database::open() {
    if (!db.open()) {
        qDebug() << "Error: connection with database failed";
        return false;
    } else {
        qDebug() << "Database: connection ok";
        return true;
    }
}

void Database::close() {
    db.close();
}

bool Database::executeQuery(const QString &queryStr) {
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Error executing query: " << query.lastError();
        return false;
    }
    return true;
}

QSqlQuery Database::executeSelectQuery(const QString &queryStr) {
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Error executing select query: " << query.lastError();
    }
    return query;
}
