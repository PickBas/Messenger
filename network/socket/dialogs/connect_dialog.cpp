#include "connect_dialog.h"
#include "ui_connect_dialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog) {
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog() {
    delete ui;
}

void ConnectDialog::on_buttonBox_accepted() {
    nick = ui->nickInput->text();
    host = ui->hostInput->text();
    port = ui->portInput->value();
    accepted();
}

