#include "headers/dialog_creating_server.h"
#include "ui_dialog_creating_server.h"

Dialog_creating_server::Dialog_creating_server(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_creating_server)
{
    ui->setupUi(this);
}

Dialog_creating_server::~Dialog_creating_server(){
    delete ui;
}

QString Dialog_creating_server::get_nick() const{
    return nick;
}

quint16 Dialog_creating_server::get_port() const{
    return port;
}

void Dialog_creating_server::on_connect_btn_clicked(){
    nick = ui->nick->text();
    port = ui->port->value();
    accept();
}

void Dialog_creating_server::on_cancel_btn_clicked(){
    reject();
}
