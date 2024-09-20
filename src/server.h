#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTextStream>
#include <QHash>

class Server : public QTcpServer {
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QHash<QString, QString> users;
    void loadUsers();
    void saveUser(const QString &username, const QString &password);
    void onReadyRead();
};

#endif // SERVER_H
