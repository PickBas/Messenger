#include "QtSocket.h"

QtSocket::QtSocket(qintptr handle, QObject *parent) : QTcpSocket(parent){
    setSocketDescriptor(handle);
    connect(this, &QtSocket::readyRead, [&](){
        emit MsReadyRead(this);
    });
    connect(this, &QtSocket::stateChanged, [&](int s){
       emit MsStateChanged(this, s);
    });
}
