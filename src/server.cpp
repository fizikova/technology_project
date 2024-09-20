#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
    loadUsers();
}

void Server::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

void Server::loadUsers() {
    QFile file("users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 2) {
                users.insert(parts[0], parts[1]);
            }
        }
    }
}

void Server::saveUser(const QString &username, const QString &password) {
    QFile file("users.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << "," << password << "\n";
    }
}

void Server::onReadyRead() {
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (socket) {
        QByteArray data = socket->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        if (!doc.isNull()) {
            QJsonObject json = doc.object();
            QString type = json["type"].toString();

            if (type == "login") {
                QString username = json["username"].toString();
                QString password = json["password"].toString();
                if (users.contains(username) && users.value(username) == password) {
                    socket->write("login-success\n");
                } else {
                    socket->write("login-fail\n");
                }
            } else if (type == "register") {
                QString username = json["username"].toString();
                QString password = json["password"].toString();
                if (!users.contains(username)) {
                    users.insert(username, password);
                    saveUser(username, password);
                    socket->write("register-success\n");
                } else {
                    socket->write("register-fail\n");
                }
            }
        }
    }
}
