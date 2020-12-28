#include "headers/dialog.h"
#include <QDebug>
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog){
    ui->setupUi(this);
    settings = new QSettings("Savings");
    ui->hostname->setText(settings->value("host").toString());
    ui->nick->setText(settings->value("nick").toString());
    ui->port->setValue(settings->value("port").toInt());
}

Dialog::~Dialog(){
    delete ui;
    delete settings;
}

QString Dialog::get_nick() const{
    return nick;
}

QString Dialog::get_host() const{
    return host;
}

quint16 Dialog::get_port() const{
    return port;
}

void Dialog::on_connect_btn_clicked(){
    host = ui->hostname->text();
    nick = ui->nick->text();
    port = ui->port->value();
    settings->setValue("host", this->host);
    settings->setValue("nick", this->nick);
    settings->setValue("port", this->port);
    accept();
}

void Dialog::on_cancel_btn_clicked(){
    reject();
}
