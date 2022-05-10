#include "server_management.h"

ServerManagement::ServerManagement(QMainWindow* mainWindow, QObject *parent)
    : QObject{parent} {
    this->mainWindow = mainWindow;
    socket = new QTcpSocket(this);
    server = nullptr;
}

ServerManagement::~ServerManagement() {
    delete socket;
    if (server != nullptr) {
        delete server;
    }
}

void ServerManagement::hostServer(quint16 port) {
    server = new Server(this);
    if (!server->startServer(port)) {
        QMessageBox::warning(mainWindow,
                             "Error",
                             "Server error: " + server->errorString(),
                             "Close");
    }
}

void ServerManagement::connectToServer(QString nick, QString host, quint16 port) {
    socket->connectToHost(host, port);
    connect(socket,
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(connectionFailure()),
            Qt::DirectConnection);
    QTextStream text(socket);
    text << "User \"" << nick << "\" connected!";
    socket->flush();
}

void ServerManagement::connectionFailure() {
    QMessageBox::warning(mainWindow, "Error", "Connection failed!");
}
