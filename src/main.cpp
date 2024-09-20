#include "mainwindow.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Database &db = Database::getInstance();
    db.open();
    db.executeQuery("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT)");
    db.close();

    MainWindow w;
    w.show();

    return a.exec();
}
