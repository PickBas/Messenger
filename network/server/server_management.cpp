#include "server_management.h"

ServerManagement::ServerManagement(QMainWindow* mainWindow, QTextEdit* messageDisplayBox, QObject *parent)
    : QObject{parent} {
    this->mainWindow = mainWindow;
    socket = new QTcpSocket(this);
    server = nullptr;
    this->messageDisplayBox = messageDisplayBox;
    connect(socket, &QTcpSocket::readyRead, this, [&](){
        readIncomingData();
    });
}

ServerManagement::~ServerManagement() {
    delete socket;
    if (server != nullptr) {
        delete server;
    }
}

void ServerManagement::hostServer(QString nick, quint16 port) {
    server = new Server(this);
    if (!server->startServer(port)) {
        QMessageBox::warning(mainWindow,
                             "Error",
                             "Server error: " + server->errorString(),
                             "Close");
    }
    this->nick=nick;
}

void ServerManagement::connectToServer(QString nick, QString host, quint16 port) {
    socket->connectToHost(host, port);
    connect(socket,
            &QAbstractSocket::errorOccurred,
            this,
            [&](QAbstractSocket::SocketError socError) {qDebug() << socError;},
            Qt::DirectConnection);
    this->nick = nick;
    QTextStream text(socket);
    text << "User \"" << nick << "\" connected!";
    socket->flush();
}

void ServerManagement::readIncomingData() {
    QTextStream text(socket);
    QString textToAppend = text.readAll();
    if (nick == textToAppend.left(nick.size()) && textToAppend[nick.size()] == ':'){
        messageDisplayBox->setAlignment(Qt::AlignRight);
        messageDisplayBox->append(textToAppend.mid(nick.size() + 2, textToAppend.size() - 1) + "\n");
    } else {
        messageDisplayBox->setAlignment(Qt::AlignLeft);
        messageDisplayBox->append(textToAppend + "\n");
    }
}
