#include "QtServer.h"

QtServer::QtServer(QObject *parent) : QTcpServer(parent){}

bool QtServer::start_server(qint16 port){
    return listen(QHostAddress::Any, port);
}

QtServer::~QtServer(){
    for(auto& i : sockets) delete i;
}

void QtServer::incomingConnection(qintptr handle){
    qDebug() << "Client connected with handle: " << handle;
    auto socket = new QtSocket(handle, this);
    sockets << socket;

    connect(socket, &QtSocket::MsReadyRead, this, [&] (QtSocket *soc){
        qDebug() << "Reading...\n";
        QTextStream t(soc);
        auto text = t.readAll();
        for(auto i : sockets){
            QTextStream m(i);
            m << text;
            i->flush();
        }
    });

    connect(socket, &QtSocket::MsStateChanged, [&] (QtSocket *soc, int st){
       if (st == QTcpSocket::UnconnectedState){
           qDebug() << "MsStateChanged with handle: " << soc->socketDescriptor();
           sockets.removeOne(soc);
       }
    });


}


